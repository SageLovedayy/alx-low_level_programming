#!/bin/bash

# Specify color codes
GREEN='\033[0;32m'  # Green
NC='\033[0m'        # No Color

# Specify the list of functions
functions=("int _putchar" "int _islower" "int _isalpha" "int _abs" "int _isupper"
           "int _isdigit" "int _strlen" "void _puts" "char *_strcpy" "int _atoi"
           "char *_strcat" "char *_strncat" "char *_strncpy" "int _strcmp"
           "char *_memset" "char *_memcpy" "char *_strchr" "unsigned int _strspn"
           "char *_strpbrk" "char *_strstr")

# Prompt user for search directory
read -p "Enter the search directory: " search_directory

# Find files containing any of the specified functions recursively
for function in "${functions[@]}"; do
    echo -e "Searching for ${GREEN}$function${NC}..."
    find "$search_directory" -type f -name '*.c' -o -name '*.h' -exec grep -l -w "$function" {} +
done

