"""
This script converts all .c/.h.cpp files
in the current directory into CRLF line endings.
"""
import os
import sys
import re

# all \n that does not have a \r before it
_replace_pattern = re.compile('(?<!\r)\n')

def _convert_file(filename):
    with open(filename, 'r', encoding='utf-8') as f:
        data = f.read()

    with open(filename, 'w', encoding='utf-8') as f:
        f.write(data)

def main():
    for (dirpath, dirnames, filenames) in os.walk('.'):
        for filename in filenames:
            if filename.endswith('.c') or filename.endswith('.h') or filename.endswith('.cpp'):
                _convert_file(os.path.join(dirpath, filename))

if __name__ == '__main__':
    main()