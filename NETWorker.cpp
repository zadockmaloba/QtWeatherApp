#include "NETWorker.h"

NETWorker::NETWorker(std::string cityName) : searchToken(cityName)
{
	curl = curl_easy_init();
	if (curl) {
		curl_easy_setopt(curl, CURLOPT_URL, zURL + cityName);
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, netCallback);
		result = curl_easy_perform(curl);
		if (result != CURL_PUSH_OK)
		{
			ERRLOG("could not connect to the internet");
		}
	}
	curl_easy_cleanup(curl);
}

NETWorker::~NETWorker()
{
}

size_t NETWorker::netCallback(char* contents, size_t size, size_t numMemb, void* user)
{
	return 1;//static_cast<NETWorker*>(user)->netCallBack_impl(contents, size, numMemb);
}

void NETWorker::getWeather(std::string city)
{
	searchToken = city;
	if (curl) {
		curl_easy_setopt(curl, CURLOPT_URL, zURL + searchToken);
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, NETWorker::netCallback);
		result = curl_easy_perform(curl);
		if (result != CURL_PUSH_OK)
		{
			ERRLOG("could not connect to the internet");
		}
	}
}

size_t netCallBack_impl(char* contents, size_t size, size_t numMemb)
{
	std::ostringstream html; html << contents;
	std::string temp = "Max Temp", temp2 = "Min Temp", temp3 = "Town:";
	std::string maxTemp = html.str().substr(html.str().find(temp) + 34, 3),
		minTemp = html.str().substr(html.str().find(temp2) + 34, 3),
		cloudCover = "";
	return size_t();
}

void getWeather(std::string city)
{
}
