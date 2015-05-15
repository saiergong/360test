#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

#include "ini_parser.h"

namespace qh
{
#define BUFFSIZE 1024
	INIParser::INIParser(){

	}
	
	INIParser::~INIParser(){

	}
	
	bool INIParser::Parse(const std::string &ini_file_path){
		int fd = open(ini_file_path.c_str(), O_RDONLY);
		if(fd == -1){
			printf("open file failed\n");
			exit(-1);
		}
		
		char *buf = (char *)malloc(sizeof(char) * BUFFSIZE);
		char *read_buf = buf;
		int read_length = 0;
		int current_bufsize = BUFFSIZE;
		int buf_length = 0;

		while((read_length = read(fd, read_buf, BUFFSIZE - 1)) != 0){
			if(read_length < 0){
				if(errno == EINTR)
					continue;
				else{
					printf("read error\n");
					exit(-1);
				}
			}
			if(read_length == BUFFSIZE - 1){
				buf = (char *)realloc(buf, current_bufsize + BUFFSIZE);
				read_buf = buf + read_length + buf_length;
			}
			buf_length += read_length;
		}

		close(fd);
		return Parse(buf, buf_length);
	}


	bool
	INIParser::Parse(const char *ini_data, 
			size_t ini_data_len, const std::string &line_seperator, const std::string &key_value_seperator){
		const char *curpos = ini_data;
		const char *line_end = NULL;
		const char *keypos = NULL;
		const char *ini_data_end = ini_data + ini_data_len;

		while(curpos < ini_data_end){
			line_end = Find(curpos, ini_data_end, line_seperator.c_str());
			if(line_end == NULL){
				keypos = Find(curpos, ini_data_end, key_value_seperator.c_str());
			}
			else if(line_end == curpos){
				curpos += line_seperator.size();
				continue;
			}
			else{
				keypos = Find(curpos, line_end, key_value_seperator.c_str());
			}
			if(keypos != NULL && keypos != curpos){
				std::string key;
				key.assign(curpos, keypos - curpos);
				std::string value;
				if(line_end != NULL)
					value.assign(keypos + 1, line_end - keypos - 1);
				else
					value.assign(keypos + 1, ini_data_end - keypos - 1);
				std::pair<std::string, std::string> pa(key, value);
				keys_.insert(pa);
				curpos = line_end + line_seperator.size();
			}
			if(line_end == NULL)
				curpos = ini_data_end;
			else
				curpos = line_end + line_seperator.size();
		}
		return true;
	}

	const char *INIParser::Find(const char *start, const char *end, const char *pattern){
		const char *p = start;
		while(p != end){
			const char *q = p;
			const char *t = pattern;
			while(*t != '\0'){
				if(*q == *t){
					q++;
					t++;
				}
				else
					break;
			}

			if(*t == '\0'){
				return p;
			}
			else{
				p++;
			}
		}

		return NULL;
	}

	const std::string& INIParser::Get(const std::string &key, bool *found){
		if(keys_.find(key) != keys_.end()){
			if(found != NULL)
				*found = true;
			return keys_[key];
		}
		else{
			if(found != NULL)
				*found = false;
			return empty;
		}
	}
}
