#pragma once
#include <qobject.h>
#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Option.hpp>
#include <curlpp/Option.inl>
#include <curlpp/Options.hpp>
#include <sstream>
#include <iostream>

class NETcurl : public QObject
{
	Q_OBJECT
public:
	NETcurl(std::string city = "nairobi");
	~NETcurl();
	std::string getData(std::string dType);
public slots:
	void getURL(std::string city);
private:
	cURLpp::Easy easeyHandle;
	const char zURL[45] = "http://www.meteo.go.ke/pages/fetch.php?town=";
	std::ostringstream pagecontents;
	std::string minTemp="", maxTemp="", cloudCover="", town="";
};
