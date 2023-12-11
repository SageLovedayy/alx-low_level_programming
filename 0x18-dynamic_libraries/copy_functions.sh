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

# Loop through each function
for function in "${functions[@]}"; do
    echo -e "Copying the first occurrence of ${GREEN}$function${NC}..."
    
    # Use find_functions.sh to get the first occurrence of the function
    result=$(./find_functions.sh "$search_directory" | grep -m 1 -w "$function")

    # Extract the function name from the underscore (_) till the end
    file_name=$(echo "$function" | sed 's/.*_//')

    # Copy the result to a file named after the function in the current directory
    echo "$result" > "$file_name.c"
done

