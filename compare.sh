files="files"



for file in "$files"/*; do
	if [ -f $file ]; then
		response="responses/$(basename "$file")"
		if [ -f $response ]; then
			res="$file - $response"
			diffs=$(diff $file $response)
			if [ -z "$diffs" ]; then
				res="\e[32mOK\e[0m $res"
			else
				res="\e[33mBAD\e[0m $res"
			fi
			echo -e $res
		fi
	fi
done
