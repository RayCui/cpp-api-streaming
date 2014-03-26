cpp-api-streaming
=================

A demo app in C++ for streaming rates using OANDA REST api and the [POCO C++ library](http://pocoproject.org/download/index.html).
A JSON parser such as [libjson](http://sourceforge.net/projects/libjson/) can be used decode the JSON response.

### Setup

Clone this repo to the location of your choice

Update the following information in main() in streaming.cpp:

    accountId
    access_token (Authorization)

Compile the file through g++ compiler. Link the poco networking component using the -lPocoNetSSL flag.

`g++ streaming.cpp -lPocoNetSSL -o streaming`

Alternatively, use the provided Makefile by running `make`.

Run the output executable file

	./streaming

### Sameple Output

	{"instrument":"EUR_USD","time":"2014-03-07T20:52:17.453618Z","bid":1.3867,"ask":1.38682}
	{"heartbeat":{"time":"2014-03-07T20:52:29.452784Z"}}
	{"instrument":"EUR_USD","time":"2014-03-07T20:52:31.430114Z","bid":1.38671,"ask":1.38685}
	{"instrument":"EUR_USD","time":"2014-03-07T20:52:31.478110Z","bid":1.38673,"ask":1.38687}

### More Information

http://developer.oanda.com/
