#pragma once

#include <QApiDoc>

namespace NotationExample {

class PersonCrud : public QObject
{
    Q_OBJECT
public:
    Q_API_DOC_INFO(){
        document->
            host("localhost").
            basePath("/v1/crud").
            consumes("application/json").
            produces("application/json").
            schemes(stpsHttp);

        document->info()
            .title("Person CRUD V1")
            .version("1.0.0")
            .termsOfService("http://www.apache.org/licenses/LICENSE-2.0.txt")
            .description("Sample API Description")
            ;

        document->info().contact()
            .name("Flavio Portela")
            .email("fmspxdev@gmail.com")
            .url("https://github.com/flaviomarcio/qtreforce-sdk")
            ;

        document->info().license()
            .name("Apache License - Version 2.0, January 2004")
            .url("http://www.apache.org/licenses/LICENSE-2.0")
            ;
    }

public:
    explicit PersonCrud(QObject*parent=nullptr);

    Q_API_DOC_PATH(search){
        path->
            operation(sptoGet)
                .operationId({})
                .responses(QApiResponse().statusCode(200))
                .parameters(QApiParameter().name("id").typeParameter(QMetaType::QUuid))
                .parameters(QApiParameter().name("name").required(true).type(QMetaType::QString));;
    }
    QVariant search();

    Q_API_DOC_PATH(person){
        path->
            operation(sptoPost)
                .operationId({})
                .responses(QApiResponse().statusCode(200))
                .parameters(QApiParameter().name("id").typeParameter(QMetaType::QUuid))
                .parameters(QApiParameter().name("name").required(true).type(QMetaType::QString));

        path->
            operation(sptoPut)
                .operationId({})
                .responses(QApiResponse().statusCode(200))
                .parameters(QApiParameter().name("id").typeParameter(QMetaType::QUuid))
                .parameters(QApiParameter().name("name").required(true).type(QMetaType::QString));;

        path->
            operation(sptoDelete)
                .operationId({})
                .responses(QApiResponse().statusCode(200))
                .parameters(QApiParameter().name("id").typeParameter(QMetaType::QUuid));
    }
    QVariant person();

};

}

