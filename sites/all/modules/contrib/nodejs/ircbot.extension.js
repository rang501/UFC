var irc = require('irc');

var publishMessageToClient;

exports.setup = function(config) {
  publishMessageToClient = config.publishMessageToClient;

  var client = new irc.Client('irc.twitch.tv', 'etendus', {
    debug: true,
    password: 'oauth:tqvprvmsf3o4800ixb2jrbwo4z3goh2',
    channels: ['#etendus']
  });

  client.addListener('message', function (from, to, message) {
    console.log(from + ' => ' + to + ': ' + message);
  });

  process.on('client-connection', function (sessionId) {
    console.log('Example extension got connection event for session ' + sessionId);
    publishMessageToClient(sessionId, {data: {subject: 'Example extension', body: 'Hello, you just connected.'}});
  })
  .on('client-authenticated', function (sessionId, authData) {
    console.log('Example extension got authenticated event for session ' + sessionId + ' (user ' + authData.uid + ')');
    publishMessageToClient(sessionId, {data: {subject: 'Example extension', body: 'Welcome, you are authenticated.'}});
  })
  .on('client-message', function (sessionId, message) {
    console.log('Example extension got message event for session ' + sessionId);
    publishMessageToClient(sessionId, {data: {subject: 'Example extension', body: 'You sent the message: ' + require('util').inspect(message)}});
  })
  .on('client-disconnect', function (sessionId) {
    console.log('Example extension got disconnect event for session ' + sessionId);
  });
};
