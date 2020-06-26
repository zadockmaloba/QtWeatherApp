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
}

NETWorker::~NETWorker()
{
}

size_t NETWorker::netCallback(char* contents, size_t size, size_t numMemb, void* user)
{
	return size * numMemb;
}
