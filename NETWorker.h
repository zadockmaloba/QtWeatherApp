#pragma once
#include <qobject.h>
#include <curl/curl.h>
#include <iostream>
#ifndef ERRLOG(x)
#define ERRLOG(x) std::cout<<"[ERROR] "<<x<<std::endl;
#endif // !LOG(x)

class NETWorker : public QObject
{
	Q_OBJECT
public:
	NETWorker(std::string cityName);
	~NETWorker();
	static size_t netCallback(char* contents, size_t size, size_t numMemb, void *user);

private:
	std::string searchToken;
	CURL* curl;
	CURLcode result;
	const char zURL[45] = "http://www.meteo.go.ke/pages/fetch.php?town=";
};

