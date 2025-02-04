#ifndef CGI_HPP
#define CGI_HPP

#include "Header.hpp"



class CGIHandler {
private:
    stringDict envVars;

public:
    CGIHandler();
    ~CGIHandler();
    string waitForCGIResponse(int *pipefd, pid_t pid, int &exitStatus);
    void exec(int *pipefd, const string& cgiScriptPath, const string& queryString, const string& requestedFilepath);
    string handleCgiRequest(const string& cgiScriptPath, const string& queryString, const string requestedFilepath, int &exitStatus);
    void setEnv(string key, string value);
    string getEnv(string key);
};

#endif