/*** Copyright (c), The Regents of the University of California            ***
 *** For more information please refer to files in the COPYRIGHT directory ***/
/* moonshotAuthRequest.h
 */

#ifndef MOONSHOT_AUTH_REQUEST_HPP
#define MOONSHOT_AUTH_REQUEST_HPP

/* This is a Metadata API call */

#include "rods.hpp"
#include "rcMisc.hpp"
#include "procApiRequest.hpp"
#include "apiNumber.hpp"
#include "initServer.hpp"
#include "icatDefines.hpp"

typedef struct {
    char *serverDN;
} moonshotAuthRequestOut_t;

#define moonshotAuthRequestOut_PI "str *ServerDN;"


#if defined(RODS_SERVER)
#define RS_MOONSHOT_AUTH_REQUEST rsMoonshotAuthRequest
/* prototype for the server handler */
int
rsMoonshotAuthRequest( rsComm_t *rsComm, moonshotAuthRequestOut_t **moonshotAuthRequestOut );

#else
#define RS_MOONSHOT_AUTH_REQUEST NULL
#endif

#ifdef __cplusplus
extern "C" {
#endif
    /* prototype for the client call */
    int
    rcMoonshotAuthRequest( rcComm_t *conn, moonshotAuthRequestOut_t **moonshotAuthRequestOut );

#ifdef __cplusplus
}
#endif
#endif	/* MOONSHOT_AUTH_REQUEST_H */
