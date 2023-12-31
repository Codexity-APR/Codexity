import os
import shutil
from gen import*
import time
from infer_test import*
from cppcheck_test import*

def main(vuln_code):
    script_dir = os.path.dirname(os.path.abspath(__file__))
    origin_scenario =vuln_code[:-1]



    #Number of round we want, the program ends after that
    MAX_ROUND = 4

    #Temperature value, between 0 and 1
    temperature = [0]

    break_counter = []

    

 
    
    #Variable that indicates if we need to regenerate a code or not
    re_genereate = 0
    


    comment_error = None



    #Function that detects if a line is an error comment
    def error_detect(line):
        if ("Avoid" in line) or ("BUG" in line) or ("FIXED" in line) or ("*/" in line) or ("Do not use" in line) or ("instead" in line):
            return False
        return True
        

    
    #Function that creates the repositories
    def create_file(i, filename, temperature, type):
        round = "round"+str(i)
        os.mkdir(filename+"/"+round)
        #os.mkdir(filename+"/"+round+"/"+"data")
        os.mkdir(filename+"/"+round+"/"+"results")
        for j in temperature:
            gen="gen"+str( int( (j%1) *10) )
            os.mkdir(filename+"/"+round+"/"+gen)
            scenario ="scenario" +str( int( (j%1) *10) )
            os.mkdir(filename+"/"+round+"/"+scenario)




    #filename = input('Enter the result folder name: ')
    filename = origin_scenario[:-1]
    filename = script_dir+"/"+filename
    #print(filename)
    if os.path.exists(filename):
        shutil.rmtree(filename)
    os.mkdir(filename)


    type = "c"
 


        
    #We start measuring the time for the whole process
    start_time = time.time()

    #Main loop
    for i in range(0,MAX_ROUND):

        #This condition checks if the files are emptpy meaning that the codes are all non-vuln
        if len(break_counter ) == len(temperature):
            break

        #We create the necessary repositories
        create_file(i, filename, temperature,type)


        #This part generates the codes
        #This condition is for round 0 which is handle differently
        if i == 0:
            #Here we need to write the scenario we wants to use
            input = open(script_dir+"/scenario/"+origin_scenario+type, "r")
            text = input.read()
            input.close()
            for t in temperature:
                if t == 0:
                    #We generate the code for temperature 0
                    print("First Generation of code")
                    answer = generation2(text)
    
                    gen="gen"+str( int( (t%1) *10) )
                    round = "round"+str(i)
                    codename="0."+type
                    path = filename+"/"+round+"/"+gen+"/"+codename

                    f = open(path, "w")
                    f.write(answer)
                    f.close()
                    f = open(filename+"/final.c","w")
                    f.write(answer)
                    f.close()
                
        #Here, it's the same but with round different from 0
        else :
            #We measure the time it takes for generating a code

            for t in temperature:
                scen_pred="scenario"+str( int( (t%1) *10))
                gen="gen"+str( int( (t%1) *10) )
                round = "round"+str(i)
                round_pred = "round"+str(i-1)

                #We want to generate the vulnerable codes that have been modified, therefore we check the precedent round
                directory = filename+"/"+round_pred+"/"+scen_pred
                path = filename+"/"+round+"/"+gen+"/"
                for filename2 in os.scandir(directory):
                    if filename2.is_file():
                        if re_genereate == 0:
                            openai_server = True
                            print("Iteration: "+str(i))
                            while openai_server:
                                try:
                                    answer = generation(prompt_original,prompt_engineering)
                                    openai_server = False
                                except Exception as e:
                                    print(e)
                            f = open(path+filename2.name, "w")
                            f.write(answer)
                            f.close()
                            
                            f = open(filename+"/final.c","w")
                            f.write(answer)
                            f.close()
 
                        else:
                            f = open(path+filename2.name, "w")
                            f.write(text)
                            f.close()
                            re_genereate = 0



        #This part is for the detection and repair

        for t in temperature:
            gen="gen"+str( int( (t%1) *10) )
            round = "round"+str(i)
            src= filename+"/"+round+"/"+gen
            src_infer =filename+"/"+round+"/"+gen+"/"+"0.c"
            result_cpp = filename+"/"+round+"/"+"results"+"/"+"cpp.xml"
            result_infer = filename+"/"+round+"/"+"results/"

            
            create_command = "cppcheck --xml-version=2 --enable=all "+src+" 2>"+result_cpp
            os.system(create_command)
            create_command = "infer run --bufferoverrun --pulse  -- gcc -c " +src_infer
            try:
                os.system(create_command)
            except:
                print("Infer Error")

            create_command = "mv infer-out/ "+result_infer
            os.system(create_command)

        for t in temperature:
            gen="gen"+str( int( (t%1) *10) )
            round = "round"+str(i)
            src= filename+"/"+round+"/"+gen
            scenario_path = filename+"/"+round+"/"+"scenario"+str( int( (t%1) *10) )
            result_cpp = filename+"/"+round+"/"+"results"+"/"+"cpp.xml"
            
            try:
                    try:
                    
                        cpp_result = extract_error_info(result_cpp)
                        cpp_cwe=None
                        none_style_list=[]
                        style_list=[]
                        if len(cpp_result) == 0:
                            cpp_error=None
                            cpp_cwe = None
                            cpp_line = None
                        else:
                            cpp_error=cpp_result[0][0]
                            cpp_cwe_non = cpp_result[0][1]
                            cpp_cwe=cpp_result[0][1]
                            cpp_line=cpp_result[0][2]
                            for i in range(0,len(cpp_result)):
                                cpp_result[i][1] = "CWE-" +str(cpp_result[i][1])
                                cpp_result[i].append("cpp")
                                none_style_list.append(cpp_result[i])
                            if len(none_style_list) == 0 and int(round[-1])!=0 :
                                cpp_cwe_non = None
                            if int(round[-1]) ==0 and  len(none_style_list) == 0:
                                cpp_cwe_non = "troll"
                            if len(none_style_list) == 0 and len(style_list)==0:
                                cpp_cwe_non = None
                    except Exception as e:
                        print(e)
                    
                    #infer
                    try:
                        infer_list = final_infer(result_infer+'infer-out/report.txt')
                    except:
                        infer_list = []
                        

                    #Ranking error
                    activate_cpp_check_prompt=0
                    if cpp_cwe_non != None:
                        activate_cpp_check_prompt=1
                        CWE = cpp_cwe
                        
                    if len(infer_list) !=0 :
                        for s in range(0,len(infer_list)):
                            if infer_list[s][0][0] =="Dead Store" or infer_list[s][0][0] =="Uninitialized Value":
                                print("")
                            else:
                                none_style_list.insert(0, [ infer_list[s][0][0],  infer_list[s][0][1] , infer_list[s][1] , "infer"] )
                                activate_cpp_check_prompt=1
                                CWE = infer_list[s][0]
                    if CWE == None:
                        quit()
 
                
                    try:

                        if activate_cpp_check_prompt == 1:
                            criticavuln = "List of vulnerabilities detected: \n"
                            if len(none_style_list) ==0:
                                criticavuln = criticavuln+"None\n"
                            for i in range(0,len(none_style_list)):
                                if none_style_list[i][-1]== "cpp":
                                    criticavuln = criticavuln + " Error type: "+str(none_style_list[i][1])+ " at line: "+str(none_style_list[i][2])+". "+"Error message: "+str(none_style_list[i][0])+"\n\n"
                                else:
                                    example_error =""
                                    for j in range(0,len(none_style_list[i][2])):
                                        example_error=example_error+"\n"+none_style_list[i][2][j]
                                    criticavuln = criticavuln +"Error: "+none_style_list[i][0]+ " "+none_style_list[i][1]+"\n Example: "+example_error+"\n\n"
                            
                            
                            comment_error = criticavuln+"\n"
                    except Exception as e:
                        print(e)
                    print(criticavuln)
                    prompt =""

                    #We add the prompt in the code
                    try :

                        modified_code = open(filename+"/"+round+"/"+gen+"/"+"0.c")
                        content = modified_code.readlines()
                        modified_code.close()

                        

                        for l in content[0: len(content)]:
                            if l.strip() and error_detect(l):
                                prompt=prompt+l
                        
                        try:
                            prompt_engineering = comment_error
                        except Exception as e:
                            print(e)
                        prompt_original = prompt
                        prompt=prompt_engineering+ prompt
                            
 
                        f = open(scenario_path+"/0.c", "w")
                        f.write(prompt)
                        f.close()
                        break

                    except Exception as e :
                        print(e)
            except:

                    break_counter.append(gen)
                    break_counter = list(dict.fromkeys(break_counter))


    end_time = time.time()

    
    f = open(filename+"/result.txt", "w")
    f.write("time for the whole process : ")
    f.write(str(end_time-start_time)+"\n")



    f.close()
    f = open(filename+"/python_script_completed.txt", "w")
    f.close()
    return end_time-start_time
    

total_time_all =[]


def mean(list):
    m = 0
    for i in list:
        m = m +i
    return m/len(list)
    
script_dir = os.path.dirname(os.path.abspath(__file__))
for vuln_code in os.listdir(script_dir+"/scenario"):
    if vuln_code[len(vuln_code)-1] == "c":
        tt= main(vuln_code)
        total_time_all.append(tt)





