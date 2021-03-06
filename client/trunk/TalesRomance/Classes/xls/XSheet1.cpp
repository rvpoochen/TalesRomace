//XSheet1
#include "XSheet1.h"
static XSheet1* instance;

XSheet1* XSheet1::record(Value v){ 
	if(instance==NULL) instance=new XSheet1();
	if(instance->doc.IsNull()){
		std::string fullPath=FileUtils::getInstance()->fullPathForFilename("XSheet1.json");
		std::string str=FileUtils::getInstance()->getStringFromFile(fullPath);
		instance->doc.Parse<0>(str.c_str());
		if(instance->doc.HasParseError()){
			log("GetParseError %s",instance->doc.GetParseError());
		}
	}
	instance->v=v;
	return instance;
}
int XSheet1::getId(){
	return doc[v.asString().c_str()]["id"].GetInt();
}
std::string XSheet1::getMsg(){
	return doc[v.asString().c_str()]["msg"].GetString();
}
