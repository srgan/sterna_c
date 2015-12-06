#ifndef Singleton_H
#define Singleton_H

#include <QDateTime>

#include <QStringList>
#include <QRect>
#include <vector>


class Singleton 
{
public: 
	typedef struct 
	{
		QDateTime fakturaData;
		QDateTime fakturaValuta;
		float iznos;
		float plateno;
		QString komintent_naziv;
		QString komintent_id;
	} tinfoFakturi;

    typedef std::vector<tinfoFakturi> tListInfoFakturi;
    static Singleton* Instance();
	int getUserID(){return m_user_id;}
	void setUserID(int userID){ m_user_id = userID;}
	QStringList getUserInfo(){return m_infoVraboten;}
	void setUserInfo(QStringList infoVraboten){ m_infoVraboten = infoVraboten;}
	tListInfoFakturi m_listFakturiS; 
    QRect getMainRect(){return m_rect;}
    void setMainRect(QRect t_rect){ m_rect = t_rect;}
    QStringList getArtikliColumnWidth(){return m_colWidth;}
    void setArtikliColumnWidth(QStringList a_colWidth){ m_colWidth = a_colWidth;}

    QStringList getKomintentiColumnWidth(){return m_colWidth_k;}
    void setKomintentiColumnWidth(QStringList a_colWidth_k){ m_colWidth_k = a_colWidth_k;}



protected: 
	//Singleton();
private:
    QRect m_rect;
    int m_user_id;
	QStringList m_infoVraboten;
	static Singleton* _instance;
    QStringList m_colWidth;
    QStringList m_colWidth_k;
};
#endif // Singleton_H
