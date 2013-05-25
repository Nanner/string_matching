//  parser.h
//
//  Projeto 2 CAL
//
//  Turma 1 Grupo D
//
//  ei11089 - Diogo Santos
//  ei11122 - Pedro Fernandes
//  ei11132 - Daniel Pereira
//

#ifndef _parser_h
#define _parser_h

#include <string>
#include <fstream>
#include <algorithm>
#include <sstream>

#include "email.h"

using namespace std;

#define IGNORE_LIST "ignoreList.txt"

class Email;

/**
 * Parses a text file (email message) to a string that can be used for matching purposes.
 */
class Parser {

public:
	static string ignoreList; /**< A string containing a list of words to be ignored during word matching. */

	/**
	 * Initializes the ignoreList variable.
	 * @return A string with the ignore list contents (empty if ignoreList.txt hasn't been found).
	 */
	static string initializeIgnoreList();

	/**
	 * Opens a file and parses it's contents to a formatted string.
	 * @param filename The name of the file with the contents.
	 * @return String with the formatted contents.
	 */
	static string parseEmail(string filename);

	/**
	 * Parses a text file to an Email object.
	 * @param filename The name of the file with the contents.
	 * @return Email object with the contents of the file.
	 */
	static Email parseEmailToObject(string filename);

	/**
	 * Parses the words in a word ignore list to a formatted string.
	 * @param filename The name of the file with the ignore list.
	 * @return String with the formatted ignore list.
	 */
	static string parseIgnoreList(string filename);
};

class FileNotFound {
	string filename;

public:
	FileNotFound(string filename): filename(filename){}
	string getName() {return filename;}
};

#endif 
