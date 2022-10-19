#! /usr/bin/bash

# saving the directory
DIR=$1
FLAG=0
# checking for the copy options
while [ True ]; do
if [ "$2" = "--copy" -o "$2" = "-c" ]; then
    FLAG=1
    shift 1
else
    break
fi
done

# checking if the directory exist
if [ -d $DIR ]
then
    echo "directory submitted successfully!"
    # Saving the current time
    now="$(date +'%Y-%m-%d')_" 
    # checking if the copy flag is raised
    if [ $FLAG = 1 ]; then
        # iterating over files in the given directory
        for fullfile in $DIR/* 
        do
        # this if condition filters [folder]s
        if [ -f "${fullfile}" ]; then
                # extracting filenames and their extensions
                filename=$(basename -- "$fullfile")
                extension="${filename##*.}"
                filename="${filename%.*}"
                # renaming files
                cp "$DIR/$filename.$extension" "$DIR/$now$filename.$extension"
                # printing the result
                echo "name: $filename.$extension  type: .$extension   -> making copy: $now${filename}.$extension"
        fi
        done

    else
        # iterating over files in the given directory
        for fullfile in $DIR/* 
        do
        # this if condition filters [folder]s
        if [ -f "${fullfile}" ]; then
                # extracting filenames and their extensions
                filename=$(basename -- "$fullfile")
                extension="${filename##*.}"
                filename="${filename%.*}"
                # renaming files
                mv "$DIR/$filename.$extension" "$DIR/$now$filename.$extension"
                # printing the result
                echo "name: $filename.$extension  type: .$extension   -> changing name to: $now${filename}.$extension"
        fi
        done
    fi

else
    echo "Error: Directory" ${DIR} "does not exists."
fi
