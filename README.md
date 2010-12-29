ydpdict-anki
============

Export irregular verbs from YDP English dictionary to anki format.

Just run "make" to build the C program and create "ydpdict-irregular-verbs.txt"
that you can import into anki to study irregular verbs. If your version of anki
complains about some lines missing fields, try:
make clean && make YDPDICT_PARSE_ARGS=-n

Requirements:
-------------

 * The dict100 dat and idx files from YDP. They are under a proprietary,
   non-free license, so please do NOT ask me for a copy.
 * The libydpdict library.
 * Python interpeter.
 * GNU make.
 * C compiler.

Copyright and License information:
----------------------------------

Copyright 2010 Marcin Owsiany <marcin@owsiany.pl>

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program.  If not, see <http://www.gnu.org/licenses/>.

