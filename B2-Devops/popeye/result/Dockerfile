FROM node:12-alpine

WORKDIR /home/node
ADD ./ ./result
WORKDIR /home/node/result
RUN npm install .
EXPOSE 80
CMD ["node", "server.js"]