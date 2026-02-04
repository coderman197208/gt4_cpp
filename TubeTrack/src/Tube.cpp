#include "Tube.h"

CTube::CTube()
{
	m_strTubeNo="";				//管号
	m_strOrderNo="";			//合同号
	m_strOrderNoOld = "";		//原合同号
	m_strItemNo = "0";			//项目号
	m_strBundleType = "000";	//管捆类型
	m_strRlNo = "";				//轧批号
	m_strMeltNo = "";			//炉号
	m_strLotNo = "";			//试批号
	m_strDiameter = "";			//外径
	m_strThickness = "";		//壁厚
	m_strLength = "";			//长度
	m_strWeight = "";			//重量
	m_strDefectCode="";			//缺陷代码
	m_strDefectText="";			//缺陷正文
	m_strLengthOk="";			//长度合格
	m_strWeightOk="";			//重量合格
	m_strHydroCheck="";			//水压实绩
	m_strInspectCheck="";		//探伤实绩
	m_strWeightPerMeter = "0";	//米重
}

CTube::CTube(const CTube& tube)
{
	m_strTubeNo = tube.m_strTubeNo;					//管号
	m_strOrderNo = tube.m_strOrderNo;				//合同号
	m_strOrderNoOld = tube.m_strOrderNoOld;			//原合同号
	m_strItemNo = tube.m_strItemNo;					//项目号
	m_strBundleType = tube.m_strBundleType;			//管捆类型
	m_strRlNo = tube.m_strRlNo;						//轧批号
	m_strMeltNo = tube.m_strMeltNo;					//炉号
	m_strLotNo = tube.m_strLotNo;					//试批号
	m_strDiameter = tube.m_strDiameter;				//外径
	m_strThickness = tube.m_strThickness;			//壁厚
	m_strLength = tube.m_strLength;					//长度
	m_strWeight = tube.m_strWeight;					//重量
	m_strDefectCode = tube.m_strDefectCode;			//缺陷代码
	m_strDefectText = tube.m_strDefectText;			//缺陷正文
	m_strLengthOk = tube.m_strLengthOk;				//长度合格
	m_strWeightOk = tube.m_strWeightOk;				//重量合格
	m_strHydroCheck = tube.m_strHydroCheck;			//水压实绩
	m_strInspectCheck = tube.m_strInspectCheck;		//探伤实绩
	m_strWeightPerMeter = tube.m_strWeightPerMeter;	//米重
}

CTube& CTube::operator=(const CTube& tube)
{
	m_strTubeNo = tube.m_strTubeNo;					//管号
	m_strOrderNo = tube.m_strOrderNo;				//合同号
	m_strOrderNoOld = tube.m_strOrderNoOld;			//原合同号
	m_strItemNo = tube.m_strItemNo;					//项目号
	m_strBundleType = tube.m_strBundleType;			//管捆类型
	m_strRlNo = tube.m_strRlNo;						//轧批号
	m_strMeltNo = tube.m_strMeltNo;					//炉号
	m_strLotNo = tube.m_strLotNo;					//试批号
	m_strDiameter = tube.m_strDiameter;				//外径
	m_strThickness = tube.m_strThickness;			//壁厚
	m_strLength = tube.m_strLength;					//长度
	m_strWeight = tube.m_strWeight;					//重量
	m_strDefectCode = tube.m_strDefectCode;			//缺陷代码
	m_strDefectText = tube.m_strDefectText;			//缺陷正文
	m_strLengthOk = tube.m_strLengthOk;				//长度合格
	m_strWeightOk = tube.m_strWeightOk;				//重量合格
	m_strHydroCheck = tube.m_strHydroCheck;			//水压实绩
	m_strInspectCheck = tube.m_strInspectCheck;		//探伤实绩
	m_strWeightPerMeter = tube.m_strWeightPerMeter;	//米重

	return *this;
}

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