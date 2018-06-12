#ifndef SETQUERY_H
#define SETQUERY_H
#include <QString>
#include <QUrl>
#include <QUrlQuery>
class SetQuery
{
private:
    QString  token;
    QString  url_str;
    QUrl  url;
    QUrlQuery query;
public:
    SetQuery();
    void setToken(QString token);
    QUrl setSignUpQuery(QString nUser,QString nPass,QString fName,QString lName);
    QUrl setLoginQuery(QString userName,QString pass);
    QUrl setLogOutQuery(QString userName,QString pass);
    QUrl setCreateGroupQuery(QString group_name,QString group_title);
    QUrl setCreateChannelQuery(QString channel_name,QString channel_title);
    QUrl setGetUserListQuery();
    QUrl setGetGroupListQuert();
    QUrl setGetChannelListQuery();
    QUrl setGetUserChatsQuery(QString username_dst);
    QUrl setGetGroupChatsQuery(QString group_dst);
    QUrl setGetChannelChatsQuery(QString channel_dst);
    QUrl setJoinGroupQuery(QString group_name);
    QUrl setJoinChannelQuery(QString channel_name);
    QUrl setSendMessageUser(QString username_dst,QString body);
    QUrl setSendMessageGroup(QString group_dst,QString body);
    QUrl setSendMessageChannel(QString channel_dst,QString body);
};

#endif // SETQUERY_H
