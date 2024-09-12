FROM node:18.9.1

WORKDIR /app

COPY package.json .

Run npm install

COPY . .

EXPOSE 5173

CMD ["npm", "run", "dev"]