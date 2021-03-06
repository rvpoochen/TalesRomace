//XSkill
#include "XSkill.h"
static XSkill* instance;

XSkill* XSkill::record(Value v){ 
	if(instance==NULL) instance=new XSkill();
	if(instance->doc.IsNull()){
		std::string fullPath=FileUtils::getInstance()->fullPathForFilename("XSkill.json");
		std::string str=FileUtils::getInstance()->getStringFromFile(fullPath);
		instance->doc.Parse<0>(str.c_str());
		if(instance->doc.HasParseError()){
			log("GetParseError %s",instance->doc.GetParseError());
		}
	}
	instance->v=v;
	return instance;
}
int XSkill::getId(){
	return doc[v.asString().c_str()]["id"].GetInt();
}
std::string XSkill::getName(){
	return doc[v.asString().c_str()]["name"].GetString();
}
int XSkill::getType(){
	return doc[v.asString().c_str()]["type"].GetInt();
}
int XSkill::getAtkType(){
	return doc[v.asString().c_str()]["atkType"].GetInt();
}
std::string XSkill::getDesc(){
	return doc[v.asString().c_str()]["desc"].GetString();
}
std::string XSkill::getIcon(){
	return doc[v.asString().c_str()]["icon"].GetString();
}
