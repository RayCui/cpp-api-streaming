cpp-api-streaming
=================

A demo app in C++ for streaming rates using OANDA open api and libcurl

### Setup

Clone this repo to the location of your choice

Make sure you have libcurl installed

	apt-get install libcurl4-gnutls-dev

Update the following information in main() in streaming.cpp:

    domain
    accountId
    access_token (Authorization)

Compile the file through g++ compiler. Link libcurl using the -lcurl flag.

    g++ streaming.cpp -lcurl -o streaming

Run the output executable file

	./streaming

### Sameple Output

	{"instrument":"EUR_USD","time":"2014-03-07T20:52:17.453618Z","bid":1.3867,"ask":1.38682}
	{"heartbeat":{"time":"2014-03-07T20:52:29.452784Z"}}
	{"instrument":"EUR_USD","time":"2014-03-07T20:52:31.430114Z","bid":1.38671,"ask":1.38685}
	{"instrument":"EUR_USD","time":"2014-03-07T20:52:31.478110Z","bid":1.38673,"ask":1.38687}

### More Information

http://developer.oanda.com/
