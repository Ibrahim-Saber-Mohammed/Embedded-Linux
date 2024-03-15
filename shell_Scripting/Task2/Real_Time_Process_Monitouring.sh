#!/usr/bin/bash

#########################################################################
# Requiremnets  : Create bash script that serves as a simple process    #
#                monitor for the system. The script should be able to   #
#                track and display information about running processes, #
#                including their PID (Process ID), name of the          #
#                executable they are executing, memory usage,           #
#                CPU time used by each process                          #
# Author        : Ibrahim Saber                                         #
# Inpuut        : None                                                  #
# OutPut        : Displays the  list of all currently running processes #
#                along with their PID, Name, Memory Usage(Kb) ,         #
#                CPU Time Used(sec).                                    #
# Date          : March 2024                                            #
# Version       : v1.0                                                  #
#########################################################################


function List_Processes () {
    local First_Line=''
    First_Line=$(ps -eo pid,ppid,user,%cpu,%mem,start,time,comm --sort=-%cpu  | head -n 1)
    echo "$(tput bold)$(tput setaf 1)${First_Line}$(tput sgr0)"
    ps -eo pid,ppid,user,%cpu,%mem,start,time,comm --sort=-%cpu  | tail -n +2 | head -n 30
   

}
function get_Process_Info () {
    local Process_Id=$1
    if [[ $# != 1 ]] ; then 
        echo "$0: Error in get_Process_Info
        Usage: get_Process_Info <process id>"
        exit 1
    else
        # Check if the process exists. If not, print an error message and exit.
        ps -eo pid,ppid,user,%cpu,%mem,start,time,comm -q ${Process_Id}
        if [ $? == 1 ] ; then  
            echo "Error: The process with ID = ${Process_Id} does not exist."
            exit 2
        fi
    fi
}

function Kill_Process() {
    local Process_Id=$1
    echo "Killing Process $Process_Id ..."
    sudo kill ${Process_Id}
    echo "Process $Process_Id Killed."
}

function Process_Statistics () {
    clear
    echo "Process Statistics: "
    echo "Total Number of Processes  = $(ps -eo pid --no-headers | wc -l)"
    echo "Memory Usage = $(free -h | awk '/^Mem:/ {print $3}')"
    echo "CPU Load = $(top -bn1 | grep "Cpu(s)" | awk '{print $2 + $4}')% "
    echo "-------------------------------"
}
function Real_Time_Monitoring () {
    while true; do
        clear
        DateandTime=$(date) 
        echo "${DateandTime}"
        echo "-------------------------------"
        Process_Statistics
        List_Processes
        sleep 5
    done
}

function Search_and_filter() {
    local search_term=$1
    echo "Searching for processes containing '$search_term'..."
    ps -eo pid,ppid,user,%cpu,%mem,start,time,comm --sort=%cpu | grep --ignore-case $search_term 
}

function Interactive_Mode() {
    local choice
    while true; do
        echo "==========================================="
        echo "Process Monitor menu "
        echo "1. List Processes."
        echo "2. Get  detailed information about a process."
        echo "3. Kill a Process"
        echo "4. Filter and list processes based on a term."
        echo "5. Real  Time Monitoring"
        echo "6. Processes statistics"
        echo "7. Quit/Exit"
        read  -p "Enter your choice [1-7] : " choice
        case "$choice" in
            1) List_Processes ;; 
            2) read -p "Enter the PID: " pid; get_Process_Info $pid   ;;
            3) read -p "Enter the PID: " pid; Kill_Process $pid ;;
            4) read -p "Enter the search term: " search_term ; Search_and_filter $search_term ;;
            5) Real_Time_Monitoring ;;
            6) Process_Statistics ;;
            7) exit ;;
            *) echo "Invalid Option!"
        esac
    done
}
function Alert_Thresholds () {
    echo "$1" # arguments are accessible through $1, $2,...
}

Interactive_Mode

#********************************************************************************************************************************
#                                                   Revision Record                                                             *
#********************************************************************************************************************************
#.*  Version     Author           Date                Comments                                                                  *
#.*  0.0.1       Ibrahim       FEB 24 2024            Created the main features  List All Processes, Kill, Find, show statistics*
#********************************************************************************************************************************




#**********************************************************************
#*                            End Of File                             *
#**********************************************************************
