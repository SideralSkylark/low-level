ls_custom() {
	dir=${1:-.}
	outfile=$2

	if [ -z "$outfile" ]; then 
		ls "$dir"	
	else
		ls "$dir" > "$outfile"
	fi
}

ls_custom "$@"
