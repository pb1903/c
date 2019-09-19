#pragma once
extern void help(void );
extern void get_file_name(char *dst_file,char *src_file);
extern char * read_src_file(unsigned long *file_length,char *src_file_name);
extern void save_file(char* text,unsigned long int length,char * file_name);
extern char * file_text_encrypt(char * src_file_text,unsigned long length,unsigned int password);
extern char * file_text_decrypt(char * src_file_text,unsigned long length,unsigned int password);