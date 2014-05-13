#include "INIParser.h"

template <class T> T INIParser::GetValue(const std::string &Section, const std::string &clef, const T &defaultValue)
{
	std::map<std::string, std::map<std::string, std::string> >::iterator _it=ini.find(Section);

	if(_it != ini.end())	// si la valeur Section n'est pas trouvé
	{
		std::map<std::string, std::string>::iterator it=_it->second.find(clef);

		if(it != _it->second.end())	// si la valeur clef n'est pas trouvé
		{
			// permet la convertion de la valeur en type std::string dans le type demandé
			T val;
			std::istringstream iss(it->second);
			iss >> val;
			return val;
		}
		else
			return defaultValue;
	}
	else
		return defaultValue;
}
template <class T> T INIParser::GetValue(const std::string &Section, const std::string &clef)
{
	std::map<std::string, std::map<std::string, std::string> >::iterator _it=ini.find(Section);
    T val;
	if(_it != ini.end())	// si la valeur Section n'est pas trouvé
	{
		std::map<std::string, std::string>::iterator it=_it->second.find(clef);

		if(it != _it->second.end())	// si la valeur clef n'est pas trouvé
		{
			// permet la convertion de la valeur en type std::string dans le type demandé

			std::istringstream iss(it->second);
			iss >> val;
		}
	}
	return val;
}
// spécialisation de la fonction pour la class std::string
template <> std::string INIParser::GetValue<std::string>(const std::string &Section, const std::string &clef, const std::string &defaultValue)
{
	std::map<std::string, std::map<std::string, std::string> >::iterator _it=ini.find(Section);

	if(_it != ini.end())
	{
		std::map<std::string, std::string>::iterator it=_it->second.find(clef);

		if(it != _it->second.end())
			return it->second;
		else
			return defaultValue;
	}
	else
		return defaultValue;
}

template <class T> void INIParser::SetValue(const std::string &Section, const std::string &clef, const T &Value)
{
	std::ostringstream oss;
	// convertion de la valeur en std::string
	oss << Value;
	// enregistrement de la valeur dans la map
	ini[Section][clef] = oss.str();
}

INIParser::INIParser(const std::string &filename, bool autoSave)
{
	std::string section, line, clef, valeur;
	size_t pos;

	AutoSave = autoSave;
	FileName = filename;

	std::ifstream file(filename.c_str());

	while (!file.eof())
	{
		std::getline (file, line);

		// suppretion des commentaires
		pos = line.find_first_of(';');
		if(pos != std::string::npos)	line.erase (line.begin() + pos, line.end());

		// continue si la ligne n'ai pas vide
		if(!line.empty())
		{
			// test si la ligne corespond a une section
			pos = line.find_first_of('[');
			if(pos != std::string::npos)
			{
				line.erase(line.begin(), line.begin() + pos+1);
				line.erase(line.begin() + line.find_first_of (']'), line.end());
				section = line;
			}
			else	// sinon elle coorespond a une clef
			{
				pos = line.find_first_of('=');
				// si le '=' a bien été trouvé
				if(pos != std::string::npos)
				{
					clef = line.substr (0, pos);
					valeur = line.substr (pos+1);

					// permet la suppretion de tout les espaces dans la clef
					while(std::string::npos != (pos = clef.find_first_of(' ')))
						clef.erase(pos);

					ini[section][clef] = valeur;
				}
			}
		}
	}

	file.close();
}

bool INIParser::save(std::string filename)
{
	std::map<std::string, std::map<std::string, std::string> >::iterator _it;
	std::map<std::string, std::string>::iterator it;

	std::ofstream file;

	if(filename == "")
		file.open(FileName.c_str());
	else
		file.open(filename.c_str());

	if(!file.is_open())	return false;

	// ecriture de la map dans le fichier demandé
	for(_it=ini.begin(); _it!=ini.end(); ++_it)
	{
		file << "[" << _it->first << "]" << std::endl;

		for(it=_it->second.begin(); it!=_it->second.end(); ++it)
			file << it->first << "=" << it->second << std::endl;
	}

	file.close();
	return true;
}

