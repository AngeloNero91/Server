// vim: ts=8 sw=4
#ifndef __INC_NETWORKBASE_H__
#define __INC_NETWORKBASE_H__

class CNetBase
{
    public:
	CNetBase();
	virtual ~CNetBase();

    protected:
	static LPFDWATCH	m_fdWatcher;
};

class CNetPoller : public CNetBase, public singleton<CNetPoller>
{
    public:
	CNetPoller();
	virtual ~CNetPoller();

	bool	Create();
	void	Destroy();
};

#endif
//martysama0134's ec11de26810c4b4081710343a364aa44
