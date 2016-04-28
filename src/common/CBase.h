/*
 ============================================================================
 Name        : CBase.h
 Author      : Rafael Gu
 Version     : 1.0
 Copyright   : GPL
 Description : The base class
 ============================================================================
 */

#ifndef _C_BASE_H_
#define _C_BASE_H_

#include <assert.h>
#include <log4c.h>
#include <ctype.h>

class CBase {
public:
	static bool initialize();
	static void uninitialize();

	static log4c_category_t *getCategory();
	static int sleep(unsigned int seconds, unsigned int ms = 0);

protected:
	CBase();
	~CBase();

private:
	static log4c_category_t *_category;
};

#define log_debug(message, args...) \
		log4c_category_log(CBase::getCategory(), LOG4C_PRIORITY_DEBUG, message, \
				##args)
#define log_info(message, args...) \
		log4c_category_log(CBase::getCategory(), LOG4C_PRIORITY_INFO, message, \
				##args)
#define log_notice(message, args...) \
		log4c_category_log(CBase::getCategory(), LOG4C_PRIORITY_NOTICE, message, \
				##args)
#define log_warn(message, args...) \
		log4c_category_log(CBase::getCategory(), LOG4C_PRIORITY_WARN, message, \
				##args)
#define log_error(message, args...) \
		log4c_category_log(CBase::getCategory(), LOG4C_PRIORITY_ERROR, message, \
				##args)
#define log_crit(message, args...) \
		log4c_category_log(CBase::getCategory(), LOG4C_PRIORITY_CRIT, message, \
				##args)
#define log_alert(message, args...) \
		log4c_category_log(CBase::getCategory(), LOG4C_PRIORITY_ALERT, message, \
				##args)
#define log_fatal(message, args...) \
		log4c_category_log(CBase::getCategory(), LOG4C_PRIORITY_FATAL, message, \
				##args)

#endif // _C_BASE_H_