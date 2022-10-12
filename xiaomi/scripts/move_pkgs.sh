#!/bin/env bash
users="users.txt"

while read line; do
    if [ -f "/home/public/$line/.conda/pkgs/" ]; then
        echo "move /home/public/$line/.conda/pkgs/* to /home/public/conda/pkgs/"
        echo "remove /home/public/$line/.conda/pkgs"
    fi
done <"$users"
