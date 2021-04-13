FROM maven:3.5-jdk-8-alpine AS builder

ADD ./ /tmp/
RUN mvn -f /tmp/pom.xml dependency:resolve
RUN mvn -f /tmp/ package

FROM openjdk:8-jre-alpine
WORKDIR /tmp/
COPY --from=builder /tmp/target /tmp/app
WORKDIR /tmp/app
CMD [ "java", "-jar", "worker-jar-with-dependencies.jar" ]