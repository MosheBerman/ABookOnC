/* Count uppercase letters in a file. */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int	c, i, letter[26];
	FILE	*ifp, *ofp;

	if (argc != 3) {
		printf("\n%s%s%s\n\n%s\n%s\n\n", 
		"Usage:	", argv[0], " infile outfile", 
		"The uppercase letters in the infile will be counted.", 
		"The results will be written in the outfile.");
	}

	ifp = fopen(argv[1], "r");
	ofp = fopen(argv[2], "w");

	for(i = 0; i < 26; ++i) { 	/* Initialize array to zero */
		letter[i] = 0;
	}

	while((c = getc(ifp)) != EOF) 
	{
		if (c >= 'A' && c <= 'Z') 	/* Find uppercase letters */
		{
			++letter[c - 'A'];
		}
	}

	for (i = 0; i < 26; ++i) 
	{
		if (i % 6 == 0) 
		{
			putc('\n', ofp);
		}

		fprintf(ofp, "%c:%5d	", 'A' + i, letter[i]);
	}

	putc('\n', ofp);

	/** These next two lines are not in the book, but mentioned during the program dissection section. */
	fclose(ifp);
	fclose(ofp);

	return 0;
}
