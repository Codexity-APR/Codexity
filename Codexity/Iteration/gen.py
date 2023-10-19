import os
import openai

#Replace by the ChatGPT API key
openai.api_key = ""

def extract_substring(s, start_str, end_str):
    """
    Extract a substring from s that starts with start_str and ends with end_str.
    """
    start_index = s.find(start_str) + len(start_str)
    end_index = s.rfind(end_str, start_index)
    if start_index < 0 or end_index < 0:
        return ""
    return s[start_index-8:end_index+1]
    
def generation(input,sast):
    response = openai.ChatCompletion.create(
    model="gpt-3.5-turbo",
    temperature= 0,
    messages=[
    {"role": "system", "content": "You are a coding editor and help the user."},
    {"role": "user", "content": "I will give you a code that has vulnerabilities inside. Then, I will give you the output of different Static Application Security Testing tools. Based on the ouput, I want you to fix the code and only give back the whole code without anything else."},
    {"role": "assistant", "content": "Certainly, I can help you analyze the C code and the SAST tools output to identify and fix any issues. Please provide the C code and the SAST tools output, and I'll do my best to assist you. I will give back the whole code fixed."},
    {"role": "user", "content": input},
    {"role": "assistant", "content": "I see the C code you've provided. To assist you further, please provide the output of the SAST tools and specify what issues or errors you're encountering. This will help me understand the problem and provide a more accurate fix for the code."},
    {"role": "user", "content": sast}
    ] )

    #print(response)
    if 'choices' in response:
        x = response['choices']
        #print( x[0]['message']['content'])
        answer = x[0]['message']['content']
        code= extract_substring(answer,"#include","}")
        return code

    
def generation2(input):
    response = openai.ChatCompletion.create(
    model="gpt-3.5-turbo",
    temperature= 0,
    messages=[
    {"role": "system", "content": "You are a coding editor and help the user."},
    {"role": "user", "content": "I will give you a incomplete code. I want you to complete the code and give back the whole code. Do not just give back the next part but the whole code"},
    {"role": "assistant", "content": "Sure! Please provide the code and to complete. I will give you the complete version of the code"},
    {"role": "user", "content": input}
    ] )

    #print(response)
    if 'choices' in response:
        x = response['choices']
        #print( x[0]['message']['content'])
        answer = x[0]['message']['content']
        #print(answer)
        code= extract_substring(answer,"#include","}")
        return code


