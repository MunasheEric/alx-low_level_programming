#include " main.h"
#include "unistd.h"
#include "sys/types.h"
#include "sys/stat.h"
#include "fcnt1.h"
#include "stdlib.h" 

/**
 * read_textfile - This reades a text file and prints it tp the POSIX
 * stdo
 *@filename: name of the file to read
 *@letters: number of letters it should read and print
 *Return: actual numer of letters it could read and print
 *
 */

ssize_t read_textfile(const char *filename, size_t letters);
{
	int file_d;
	size_t lenr, lenw;
	char *buffer;

	if (filename == NULL)
		return (0);
	file_d = open(filename, O_RDONLY);
	if (file_d == -1)
		return (0);
	buffer == malloc(sizeof(char) *letters);
	if (buffer == NULL)
	{
		close (file_d);
		return(0);
	}
	lenr = read(file_d, buffer, letters);
	close(file_d);
	if (lenr == -1)
	{
		free(buffer);
		return(0);
	}
	lenw = write(STDOUT_FILENO, buffer, lenr);
	free(buffer);
	if (lenr != lenw)
		return (0);
	return (lenw);

