#pragma once

#include <iostream>
#include <string>

using namespace std;

class CTube
{
public:
	CTube() = default;
	CTube(const CTube &) = default;
	~CTube() = default; // 也可以省略这一行，默认析构就是空的
	CTube &operator=(const CTube &) = default;

	string m_strTubeNo;				  // 管号
	string m_strOrderNo;			  // 合同号
	string m_strOrderNoOld;			  // 原合同号
	string m_strItemNo = "0";		  // 项目号
	string m_strBundleType = "000";	  // 管捆类型
	string m_strRlNo;				  // 轧批号
	string m_strMeltNo;				  // 炉号
	string m_strLotNo;				  // 试批号
	string m_strDiameter;			  // 外径（毫米）
	string m_strThickness;			  // 壁厚（毫米）
	string m_strLength;				  // 长度（米）
	string m_strWeight;				  // 重量（公斤）
	string m_strDefectCode;			  // 缺陷代码
	string m_strDefectText;			  // 缺陷正文
	string m_strLengthOk;			  // 长度合格
	string m_strWeightOk;			  // 重量合格
	string m_strHydroCheck;			  // 水压实绩
	string m_strInspectCheck;		  // 探伤实绩
	string m_strWeightPerMeter = "0"; // 米重
};

std::string trimString(std::string str)
{
	if (str.empty())
	{
		return str;
	}

	int s = str.find_first_not_of(" ");

	if (s < 0)
	{
		str = "";
		return str;;
	}

	int e = str.find_last_not_of(" ");
	str = str.substr(s, e - s + 1);
	return str;
}
