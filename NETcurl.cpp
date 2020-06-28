#include "NETcurl.h"

NETcurl::NETcurl(std::string city)
{
	//getURL(city);
}

NETcurl::~NETcurl()
{
}

std::string NETcurl::getData(std::string dType)
{
	if (dType == "max_t") return maxTemp;
	else if (dType == "min_t") return minTemp;
	else if (dType == "town") return town;
	else return "ERROR";
}

void NETcurl::getURL(std::string zcity)
{
	pagecontents.clear();
	curlpp::Cleanup clean;
	cURLpp::initialize();
	std::string temp = "Max Temp", temp2 = "Min Temp", temp3 = "Town:";
	easeyHandle.setOpt(new cURLpp::Options::Url(zURL + zcity));
	easeyHandle.setOpt(new cURLpp::Options::WriteStream(&pagecontents));
	easeyHandle.perform();
	//pagecontents << curlpp::Options::Url(zURL + zcity);
	maxTemp = pagecontents.str().substr(pagecontents.str().find(temp) +34, 3);
	minTemp = pagecontents.str().substr(pagecontents.str().find(temp2) + 34, 3);
	town = pagecontents.str().substr(pagecontents.str().find(temp3) + 13 + temp3.size(), 3);
	pagecontents.clear();
	curlpp::terminate();
}
