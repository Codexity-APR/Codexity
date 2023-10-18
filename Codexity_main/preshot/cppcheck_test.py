import xml.etree.ElementTree as ET


def extract_error_ids(xml_file):
    """Extracts the error IDs from the XML file, ignoring 'missingIncludeSystem'."""
    tree = ET.parse(xml_file)
    root = tree.getroot()
    
    error_ids = []
    for error in root.findall('.//error'):
        error_id = error.attrib['id']
        if error_id != 'missingIncludeSystem':
            error_ids.append(error_id)
    
    return error_ids

def extract_error_info(xml_file):
    """Extracts the error message, CWE and first line of each error from the XML file."""
    tree = ET.parse(xml_file)
    root = tree.getroot()
    
    error_info = []
    for error in root.findall('.//error'):
        error_id = error.attrib['id']
        if error_id != 'missingIncludeSystem' and error_id != 'syntaxError':
            message = error.attrib['msg']
            severity =error.attrib['severity']
            cwe = error.attrib['cwe']
            location = error.find('.//location')
            line = location.attrib['line']
            error_info.append([message,cwe,line,severity])
    
    return error_info

def extract_first_line(xml_file):
    """Extracts the first line of each error from the XML file."""
    tree = ET.parse(xml_file)
    root = tree.getroot()
    
    first_lines = []
    for error in root.findall('.//error'):
        error_id = error.attrib['id']
        if error_id != 'missingIncludeSystem':
            location = error.find('.//location')
            line = location.attrib['line']
            first_lines.append(int(line))
    
    return first_lines
