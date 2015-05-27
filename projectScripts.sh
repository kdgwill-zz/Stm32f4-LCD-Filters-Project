#!/bin/bash

# NOTE: TO LOAD IN TERMINAL USE "source projectScripts.sh" IN ORDER TO USE THIS SCRIPT
# NOTE: Its nice to update your .bashrc file to do this automatically but I don't expect you to
#
#For those who seemed to have issues with git and compiling please use this file as a type of shortcut
#Its not the best and I did not add support for additional flags but it should help with compiling and
#updating your git repositories

__RANDOM_TEMPROARY_VARIABLE__=`pwd`

################################################
# Name: makeFlashProject
# Desc: flash project to board
################################################
makeFlashProject() {
	(cd $__RANDOM_TEMPROARY_VARIABLE__/tft-lcd-support && exec scons mode=debug mcu=f4 hse=8000000 -j2)
	(cd $__RANDOM_TEMPROARY_VARIABLE__/tft-lcd-support/examples/pictureFrame/build/debug-f4-8000000 && exec st-flash write pictureFrame.bin 0x8000000)
}

################################################
# Name: vikFlashProject
# Desc: flash project to board
################################################
vikFlashProject() {
	(cd $__RANDOM_TEMPROARY_VARIABLE__/tft-lcd-support && exec scons mode=debug mcu=f4 hse=8000000 -j2)
	(cd $__RANDOM_TEMPROARY_VARIABLE__/tft-lcd-support/examples/ili9325/build/debug-f4-8000000 && exec st-flash write ili9325.bin 0x8000000)
}


################################################
# Name: gitUpdate
# Desc: Sync Git with repo
################################################
gitUpdate() {
	git pull origin
	git fetch origin -v
	git fetch upstream -v
	git merge upstream/master
	#exit $1
}

################################################
# Name: __printUSAGE
# Desc: prints a USAGE message and then exits
# Args: $@ -> message to print
################################################
__printUSAGE() {
	echo -e "\e[31mUSAGE:" $@ "\e[0m"
	#exit $1
}

################################################
# Name: __seperateOutputComments
# Desc: Seperate output for aesthetic reasons
# Args: $@ -> message to print
################################################
__seperateOutputComments() {
	#asthetics
	echo -e ".\n.\n.\n.\n.";
	#exit $1
}
################################################
# Name: ___setCFP
# Desc: constructs the input output files to be compiled
# Args: $1 -> input filename
#	$2 -> output filename (Optional)
################################################
__constructIO(){
	local input="$1";
	ext=${input##*.}; #get extension
	output=${input%.$ext}; #create default output by removing ext
	output=${2:-"$output"}; #Create output file by removing extension
	ext=${ext^^}; #to uppercase
	echo -e "Compiling \e[33m$ext\e[0m file \e[93m\e[4m$input\e[0m ...";
}
################################################
# Name: ___setCFP
# Desc: Sets the permissions of the compiled file
# Args: $1 <- The file whose permission needs to be set
#	$2 <- EXIT CODE
################################################
__setCFP(){
	if [ -f $1 -a $2 -eq 0 ];then #"$?" -eq 0 ];then
		chmod 744 $output;
		echo -e "Created file \e[32m\e[1m$output\e[0m and set permissions for user execution.";
	else
		#echo -e "Error Compiling File" # not needed compiler error is enough
		if [ -f $output ];then #clean up previous file generated if any
			rm $output
		fi
	fi
}
################################################
# Name: comp
# Desc: Compiles A c++ program into the programs directory
# Args: $1 -> input
#	$2 -> output
################################################
__comp(){
	COMP_ARGS="-Wall -Wextra -g";
	case "$1" in
		*.cpp)#compile C++ code
			if type clang > /dev/null; then #check if clang exists
				clang++ $COMP_ARGS -std=c++11 $1 -o $2; #small issue with typedef, developers bug
			else
				echo "Clang++ is not installed defaulting to g++"
				g++ $COMP_ARGS -std=gnu++11 $1 -o $2;
			fi
		;;
		*.c)#compile C code
			if type clang > /dev/null; then #check if clang exists
				clang $COMP_ARGS -std=gnu11 $1 -o $2;
			else
				echo "Clang is not installed defaulting to gcc"
				gcc $COMP_ARGS -std=gnu11 $1 -o $2;
			fi
		;;
		*)#default statement
			echo -e "\e[31mBe sure the file has the proper file extension ie .c, .cpp,...\e[0m";
			__printUSAGE "comp /path/to/program";
		;;
	esac
	#
	#
	#Check if file was created successfully, if it was set permissions for easy execution
	__setCFP $2 $?;
}
################################################
# Name: comp
# Desc: Compiles A c++ program into the programs directory
# Opts: pso
#	-p (Default) compile files together as a project
#	-s compile files seperately
#	-o Set output filename directly after option init
# Args: $1 ->
#	$2 ->
################################################
comp(){
	#
	#
	#CHECK OPTIONS
	isProject=true;
	unset input
	unset output
	unset ext
	unset OPTIND
	unset OPTARG
	while getopts ":spo:" opt; do
		case $opt in
			o)#Custom output filename, otherwise first file given name used
				output="$OPTARG";
			;;
			p)#Compile A Set of Project Files
				isProject=true;
			;;
		     	s)#Compile A Set of Files Seperately
			     	isProject=false;
			;;
			\?)#default
				echo "Invalid option: -$OPTARG";
				return 1;
			;;
			:)#Error catching
			 	 echo "Option -$OPTARG requires an argument.";
			         return 1;
			 ;;
		esac
	done
	shift $((OPTIND-1));#remove option from input
	#
	#
	#Determine how files should be handle
	if [ "$isProject" = true ]; then
		echo "Project Compilation";
		#aesthetics
		__seperateOutputComments;
		#Compile as Project
		#Determine file outputName
		__constructIO $1 $output;
		#Compile
		__comp "$*" $output; #quoted "$*" passes spaced string as single string to func
	else
		echo "Singular Compilation"
		#Compile Seperately
		for var in "$@"; do
			#aesthetics
			__seperateOutputComments;
			#Determine file outputName
			__constructIO $var;
			#compile
			__comp $var $output;
		done
	fi
	#
	#
	#UNSET local variables
	unset input
	unset output
	unset OPTIND
	unset OPTARG
}
