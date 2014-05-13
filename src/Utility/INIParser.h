#ifndef INIPARSER_H
#define INIPARSER_H

#include <fstream>
#include <sstream>
#include <string>
#include <map>

class INIParser
{
	private:
		std::map<std::string, std::map<std::string, std::string> > ini;
		std::string FileName;
		bool AutoSave;

	public:
		INIParser(const std::string &, bool=false);
		~INIParser()
		{
			if(AutoSave)	save();
			ini.clear();
		};
		// permet de recupérer une valeur, et retourne une valeur par defaut si la clef n'est pas trouvé
		template <class T> T GetValue(const std::string &, const std::string &, const T &);
		// permet de recupérer une valeur
		template <class T> T GetValue(const std::string &, const std::string &);
		// permet d'enregistrer une valeur, ou dans modifier une existante.
		template <class T> void SetValue(const std::string &, const std::string &, const T &);
		// enregistre la map dans un fichier.
		bool save(std::string="");
};
#endif
