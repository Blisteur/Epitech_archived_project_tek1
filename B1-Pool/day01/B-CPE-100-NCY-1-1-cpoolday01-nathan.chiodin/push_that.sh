#!/bin/bash
if [[ -z "$1" ]]
then
    message='modifying with push that'
else
    message=$1
fi 
git add ./
git commit -m "$message"
git push
