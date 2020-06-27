#include "NETcurl.h"

NETcurl::NETcurl(std::string city)
{
	getURL(city);
}

NETcurl::~NETcurl()
{
}

std::string NETcurl::getData(std::string dType)
{
	if (dType == "max_t") return maxTemp;
	else if (dType == "min_t") return minTemp;
}

void NETcurl::getURL(std::string city)
{
	cURLpp::initialize();
	std::string temp = "Max Temp", temp2 = "Min Temp", temp3 = "Town:";
	easeyHandle.setOpt(cURLpp::Options::Url(zURL + city));
	easeyHandle.setOpt(cURLpp::Options::WriteStream(&pagecontents));
	maxTemp = pagecontents.str().substr(pagecontents.str().find(temp) + 34, 3);
	minTemp = pagecontents.str().substr(pagecontents.str().find(temp2) + 34, 3);
	easeyHandle.perform();
	cURLpp::terminate();
}
