#!/usr/bin/bash

#########################################################################
# Requiremnets  : Organize Files in a specified Directory               #
# Author        : Ibrahim Saber                                         #
# Inpuut        : Directory Path                                        #
# OutPut        : Create Sub Directories Based on the file extensions   #
#                and move files to their corresponding directories.     #
# Version       : v1.0                                                  #
#########################################################################


function ExtractFileExtensions () {
    declare DIRE_PATH # variable to hold the Directory Path
    DIRE_PATH=$1      # assign the Directory Path that is passed during Function Call
    # Iterate over all the files in the Directory
    # check  if $DIRE_PATH/<ITEM> is a directory or is just a file
    # if ITEM is  a File then get its extension using ${ITEM##*.}
    # else continue
    
    for ITEM in ${DIRE_PATH}/* ; do
        if [ -f  "$ITEM" ] ; then
            FILEEXIST="${ITEM##*.}" # Get the file extension from the filename
            FILEEXIST=${FILEEXIST,,}  # Convert the File EXtension to lower case
            DIR_NAME="$FILEEXIST" # create the Directory name based on  the File EXTENSION
            if [[ $FILEEXIST == ${ITEM,,} || "$FILEEXIST" == "unknown" ]]; then
                DIR_NAME="misc" # create the Directory name to the files.unknown and files without any extensions
            fi
            mkdir -p "${DIRE_PATH}/$DIR_NAME"  # Make sure the Directory Exists otherwise make  it
            mv  --verbose "$ITEM"  "${DIRE_PATH}/$DIR_NAME/" # Move The FIle to its Corresponding Directory
        fi
    done
}
   

function main () {
    declare DirectoryPath
    DirectoryPath=$1
    if [ -e $DirectoryPath ]; then
        #organize the files 

        ExtractFileExtensions "$DirectoryPath"
	else
        echo "Error: The directory '$DirectoryPath' does not exist"
        exit 255
    fi
}

# validate the Input Argument from the  Command Line
if [ -z "$1" ]; then
    echo "****************************************************"
    echo " Please Provide the Directory Path ."
    echo " Usage : bash organize_files.sh <directory path>"
    echo "****************************************************"

else
# Call main Function
    main "$1"
fi

#*************************************************************************************************************************
#                                                   Revision Record                                                      *
#*************************************************************************************************************************
#.*  Version     Author           Date                Comments                                                           *
#.*  0.0.1       Ibrahim       2024 FEB 24            Created the main Function and the  ExtractFileExtensions Function  *
#.*  0.0.2       Ibrahim       2024 FEB 29            Handled the .unknown files and the files without any extensions    * 
#*************************************************************************************************************************




#**********************************************************************
#*                            End Of File                             *
#**********************************************************************