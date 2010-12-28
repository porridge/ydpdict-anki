# ydpdict-anki - export irregular verbs from YDP English dictionary to anki format
# Copyright 2010 Marcin Owsiany <marcin@owsiany.pl>
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

DICT_FILES=$(addprefix /usr/local/share/ydpdict/dict100.,dat idx)
CFLAGS = -g -Werror
LDFLAGS = -lydpdict

ydpdict-irregular-verbs.txt: ydpdict-parse ydpdict-dump.htmls
	./$< ydpdict-dump.htmls > $@

ydpdict-dump.htmls: ydpdict-dump $(DICT_FILES)
	./$< $(DICT_FILES) | egrep -v '^<(.DOCTYPE html|.xml ver)' > $@

clean:
	rm -f ydpdict-irregular-verbs.txt ydpdict-dump.htmls ydpdict-dump
