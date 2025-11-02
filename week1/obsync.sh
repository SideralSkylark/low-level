#!/usr/bin/env bash
set -euo pipefail

DIR="$HOME/Documents/Obsidian-Vault" 

add_ssh_key() { 
	output=$(ssh-add -l 2>/dev/null) 
	if [ -n "$output" ]; then 
		echo "keys already loaded" 
		return 0 
	fi 

	if ssh-add ~/.ssh/skylark; then 
		echo "key added successfully" 
		return 0 
	else 
		echo "error adding key" 
		return 1 
	fi 
} 

has_origin() { 
	cd $DIR || return 1
	if git remote -v | grep -q "^origin"; then
		return 0
	else 
		return 1
	fi
}

set_origin() {
	if ! has_origin; then
		echo "Provide the origin address"
		read origin
		git remote add origin "$origin"
	fi
	return 0
}

sync() {
	cd $DIR || return 1
	git add .
	date=$(date + "%Y-%m-%d %H:%M:%S")
	git commit -m "update $date" || echo "Nothing to commit"
	git push -u origin main
}

main() {
	add_ssh_key
	set_origin
	sync
}

# A shell script to sync my obsidian files to git
main
