import json

def extract_bug_details(json_file_path):
    list=[]
    with open(json_file_path, 'r') as f:
        try:
            json_data = json.load(f)
            for i in range(0,len(json_data)):
                bug_type = json_data[i]['bug_type']
                #print(bug_type)
                qualifier = json_data[i]['qualifier']
                #print(qualifier)
                line = json_data[i]['line']
                #print(line)
                list.append([bug_type,qualifier,line])
            return list
        except:
            list=[]
    
    return list
#bug_type, qualifier, line = extract_bug_details('infer-out/report.json')
#print(bug_type, qualifier, line)

def separate_elements(filename):
    with open(filename, 'r') as file:
        data = file.read()
    
    elements = data.split('\n\n')
    return elements

def extract_lines(input_string):
    lines = input_string.strip().split('\n')
    second_third = lines[1:3]
    rest = lines[3:]
    return [second_third, rest]

def extract_after_error(input_string):
    error_index = input_string.lower().find('error: ')
    if error_index != -1:
        result = input_string[error_index + len('error: '):].strip()
        return result
    else:
        return None

def final_infer(filename):
    try:
        file_elements = separate_elements(filename)
        result=[]
        for i in range(0,len(file_elements)-1):
            sep = extract_lines(file_elements[i])
            result2= extract_after_error(sep[0][0])
            sep[0][0]= result2
            result.append(sep)
        return result
    except:
        return []
