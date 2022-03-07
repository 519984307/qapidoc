#include "./qapidoc_common_types.h"

Q_GLOBAL_STATIC_WITH_ARGS(QStringList,staticQApiRequestParameterInLocation,({"", "query", "header", "path", "formData", "body"}));
Q_GLOBAL_STATIC_WITH_ARGS(QStringList,staticQApiPathTypeOperationList,({"", "get", "post", "put", "delete", "options", "head", "patch", "trace"}));
Q_GLOBAL_STATIC_WITH_ARGS(QStringList,staticQApiTypeParameter,({"defined", "string", "number", "int", "boolean", "array", "file"}));
Q_GLOBAL_STATIC_WITH_ARGS(QApiTransferProtocolSchemeList, staticQApiTransferProtocolSchemeList,({stpsNotDefined, stpsHttp, stpsHttps, stpsWs, stpsWss}));
Q_GLOBAL_STATIC_WITH_ARGS(QApiTransferProtocolSchemeHash, staticQApiTransferProtocolSchemeHash,
                          (
                              {
                                  {"", stpsNotDefined},
                                  {"null", stpsNotDefined},
                                  {"undefined", stpsNotDefined},
                                  {"notdefined", stpsNotDefined},
                                  {"stpsnotdefined", stpsNotDefined},
                                  {"undefined", stpsNotDefined},
                                  {"http", stpsHttp},
                                  {"stpshttp", stpsHttp},
                                  {"https", stpsHttps},
                                  {"stpshttps", stpsHttps},
                                  {"ws", stpsWs},
                                  {"stpsws", stpsWs},
                                  {"wss", stpsWss},
                                  {"stpswss", stpsWss}
                              }
                              ));

Q_GLOBAL_STATIC_WITH_ARGS(QApiPathTypeOperationHash, staticQApiPathTypeOperationHash,
                          (
                              {
                                  {"", sptoNotDefined},
                                  {"sptonotdefined", sptoNotDefined},
                                  {"sptoget", sptoGet},
                                  {"sptopost", sptoPost},
                                  {"sptoput", sptoPut},
                                  {"sptodelete", sptoDelete},
                                  {"sptooptions", sptoOptions},
                                  {"sptohead", sptoHead},
                                  {"sptopatch", sptoPatch},
                                  {"sptotrace", sptoTrace},

                                  {"notdefined", sptoNotDefined},
                                  {"get", sptoGet},
                                  {"post", sptoPost},
                                  {"put", sptoPut},
                                  {"delete", sptoDelete},
                                  {"options", sptoOptions},
                                  {"head", sptoHead},
                                  {"patch", sptoPatch},
                                  {"trace", sptoTrace}

                              }
                              ));


const QStringList &qapi_TypeParameter()
{
    return*staticQApiTypeParameter;
}

const QStringList &qapi_pathTypeOperationList()
{
    return*staticQApiPathTypeOperationList;
}

const QStringList &qapi_requestParameterInLocation()
{
    return*staticQApiRequestParameterInLocation;
}

const QApiTransferProtocolSchemeList &qapiTransferProtocolScheme()
{
    return*staticQApiTransferProtocolSchemeList;
}

const QApiTransferProtocolSchemeHash &qapiTransferProtocolSchemeHash()
{
    return*staticQApiTransferProtocolSchemeHash;
}

const QApiPathTypeOperationHash &qapi_PathTypeOperationHash()
{
    return*staticQApiPathTypeOperationHash;
}
