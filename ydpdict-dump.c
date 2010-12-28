/*
 * ydpdict-anki - export irregular verbs from YDP English dictionary to anki format
 * Copyright 2010 Marcin Owsiany <marcin@owsiany.pl>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include <ydpdict/ydpdict.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	ydpdict_t *dict;
	uint32_t count, i;

	if (argc != 3) {
		fprintf(stderr, "Usage: dump <datfile> <idxfile>\n");
		exit(1);
	}
	dict = ydpdict_open(argv[1], argv[2], YDPDICT_ENCODING_UTF8);
	if (! dict) {
		perror("opening dictionary failed");
		exit(1);
	}
	count = ydpdict_get_count(dict);
	for (i = 0; i < count; i++) {
		unsigned char *tmp = ydpdict_read_xhtml(dict, i);
		printf("%s\n", tmp);
		free(tmp);
	}
	
	ydpdict_close(dict);
	return 0;
}
