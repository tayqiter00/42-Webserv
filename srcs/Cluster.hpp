#ifndef CLUSTER_HPP
# define CLUSTER_HPP

#include "includes/Webserv.hpp"
#include "Exception.hpp"
#include "ServerBlock.hpp"

class Cluster
{
	public:
		Cluster(void) {};
		Cluster(std::string &configPath);
		~Cluster(void) {};

		std::vector<std::string>	tokenizeConfig(std::string &configPath);
		void						parseConfig(std::vector<std::string> tokens);
		class	ConfigFileException : public Exception
		{
			public:
				ConfigFileException(const std::string& message)
					: Exception(message) {}
		};

	private:
		std::vector<ServerBlock>	_servers;
};

std::string	strTrim(std::string str, std::string delims);

#endif