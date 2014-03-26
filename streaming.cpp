#include <iostream>
#include <iterator>
#include <string>
#include <sstream>

#include <Poco/Net/HTTPSClientSession.h>
#include <Poco/Net/HTTPRequest.h>
#include <Poco/Net/HTTPResponse.h>
#include <Poco/Net/SSLManager.h>
#include <Poco/StreamCopier.h>
#include <Poco/Path.h>
#include <Poco/URI.h>
#include <Poco/Exception.h>

using namespace Poco;
using namespace Poco::Net;
using namespace std;

void handleStream(streambuf* stream_buffer)
{
    std::istreambuf_iterator<char> eos; // end-of-range iterator
    std::istreambuf_iterator<char> iit (stream_buffer); // stream iterator
    string str;

    while (iit!=eos) {
        ostringstream oss;
        while (*iit != '\n') {
            oss << *iit++;
        }
        
        //print the tick 
        cout << oss.str() << endl;
        
        *iit++;
    }
}

int main ()
{
    try {
        const Context::Ptr context = new Context(Context::CLIENT_USE, "", "", "", Context::VERIFY_NONE, 9, false, "ALL:!ADH:!LOW:!EXP:!MD5:@STRENGTH");

        // prepare session
        URI uri("https://stream-fxpractice.oanda.com/v1/quote?accountId=<your-account-id>&instruments=EUR_USD");
            
        HTTPSClientSession session(uri.getHost(), uri.getPort(), context);
        session.setKeepAlive(true);

        // prepare path
        string path(uri.getPathAndQuery());
        if (path.empty()) path = "/";

        // send request
        HTTPRequest req(HTTPRequest::HTTP_GET, path, HTTPMessage::HTTP_1_1);
        req.set("Authorization", "Bearer <your-access-token>");
        session.sendRequest(req);

        // get response
        HTTPResponse res;
        istream& rs = session.receiveResponse(res);

        // handle response
        ostringstream out_string_stream;
        handleStream(rs.rdbuf());
    }
    catch (const Exception &e)
    {
        cerr << e.displayText() << endl;
    }
}

