#include "PositionBase.h"
#include <iostream>
#include <sstream>
#include <iomanip>

CPositionBase::CPositionBase()
{
	m_bTriggerEnabled	= true;
	m_bUpdateTagEnabled = true;
	m_bWbReleased = true;
}

void CPositionBase::GetDateTime(struct tm & t)
{
	time_t now;             //声明time_t类型变量
	time(&now);				//获取系统日期和时间
	localtime_r(&now, &t);  //获取当地日期和时间
}

void CPositionBase::GetDateTimeString(string & dateStr, string & timeStr)
{
	struct tm t;			//tm结构指针
	time_t now;             //声明time_t类型变量
	time(&now);				//获取系统日期和时间
	localtime_r(&now, &t);  //获取当地日期和时间

	// 输出 tm 结构的各个组成部分
	std::stringstream ss1, ss2;
	ss1 << 1900 + t.tm_year << setw(2) << setfill('0') << 1 + t.tm_mon << setw(2) << setfill('0') << t.tm_mday;
	dateStr = ss1.str();
	ss2 << setw(2) << setfill('0') << t.tm_hour << setw(2) << setfill('0') << t.tm_min << setw(2) << setfill('0') << t.tm_sec;
	timeStr = ss2.str();
}

bool CPositionBase::Push(CTube &tube, int mode)	//0根据信号自动，1异常情况下干预
{

	if (m_tubes.size() == 0)
	{
		if (m_bTriggerEnabled)
		{
			EntryTriggerBeforePush(tube);
		}
		m_tubes.push_back(tube);
		UpdateTag();
		if (m_bTriggerEnabled)
		{
			EntryTrigger(tube);
		}
		return true;
	}
	else
	{
		std::cout << "工位上已有管子，无法插入管子数据！" << std::endl;
		return false;
	}
}

bool CPositionBase::Pop(CTube *pTube, int mode)
{
	if (m_tubes.size() > 0)
	{
		*pTube = m_tubes[0];
		m_tubes.pop_back();
		UpdateTag();
		if (m_bTriggerEnabled)
		{
			ExitTrigger(*pTube);
		}	
		return true;
	}
	else
	{
		return false;
	}
}

bool CPositionBase::Peek(CTube *pTube)
{
	if (m_tubes.size() > 0)
	{
		*pTube = m_tubes[0];
		return true;
	}
	else
	{
		return false;
	}
}

bool CPositionBase::IsEmpty()
{
	return m_tubes.empty();
}

void CPositionBase::Clear()
{
	m_tubes.clear();
	UpdateTag();
}

void CPositionBase::Modify()
{}

void CPositionBase::RestoreFromTag()
{
}

void CPositionBase::UpdateTag()
{
}

void CPositionBase::EntryTriggerBeforePush(CTube & tube)
{
}

void CPositionBase::EntryTrigger(const CTube & tube)
{
}

void CPositionBase::ExitTrigger(const CTube & tube)
{
}

void CPositionBase::SetOccupiedStatus(bool signal)
{
	m_bOccupied = signal;
}

bool CPositionBase::IsOccupied()
{
	return m_bOccupied;
}

void CPositionBase::EnableTrigger()
{
	m_bTriggerEnabled = true;
}

void CPositionBase::DisableTrigger()
{
	m_bTriggerEnabled = false;
}

void CPositionBase::EnableUpdateTag()
{
	m_bUpdateTagEnabled = true;
}

void CPositionBase::DisableUpdateTag()
{
	m_bUpdateTagEnabled = false;
}

void CPositionBase::DebugOut()
{

	CTube tube;
	if (!Peek(&tube))
	{
		std::cout << "没有管子信息" << std::endl;
		return;
	}
	std::cout << "管号    :" << tube.m_strTubeNo << std::endl;
	std::cout << "合同号  :" << tube.m_strOrderNo << std::endl;
	std::cout << "原合同号:" << tube.m_strOrderNoOld << std::endl;
	std::cout << "项目号  :" << tube.m_strItemNo << std::endl;
	std::cout << "管捆类型:" << tube.m_strBundleType << std::endl;
	std::cout << "轧批号  :" << tube.m_strRlNo << std::endl;
	std::cout << "炉号    :" << tube.m_strMeltNo << std::endl;
	std::cout << "试批号  :" << tube.m_strLotNo << std::endl;
	std::cout << "外径    :" << tube.m_strDiameter << std::endl;
	std::cout << "壁厚    :" << tube.m_strThickness << std::endl;
	std::cout << "长度    :" << tube.m_strLength << std::endl;
	std::cout << "重量    :" << tube.m_strWeight << std::endl;
	std::cout << "缺陷代码:" << tube.m_strDefectCode << std::endl;
	std::cout << "缺陷正文:" << tube.m_strDefectText << std::endl;
	std::cout << "长度合格:" << tube.m_strLengthOk << std::endl;
	std::cout << "重量合格:" << tube.m_strWeightOk << std::endl;
	std::cout << "水压实绩:" << tube.m_strHydroCheck << std::endl;
	std::cout << "探伤实绩:" << tube.m_strInspectCheck << std::endl;
	
	return;
}
