#ifndef TETRIS_APP_H
#define TETRIS_APP_H

#include <Logic/ButtonLogic.h>
#include <Logic/XBoardLogic.h>
#include <Service/Sched/Scheduler.h>

#include "TetrisGame.h"
#include "app.h"

namespace hitcon {

namespace app {

namespace tetris {

enum XboardPacketType : uint8_t {  // XBOARD
  PACKET_ATTACK = 1,
  PACKET_GAME_START,
  PACKET_GAME_OVER,
  PACKET_GAME_OVER_ACK,
  PACKET_ABORT_GAME,
};

enum {  // player count
  SINGLEPLAYER = 1,
  MULTIPLAYER,
};

// set mode before changing to tetris app
void SetSingleplayer();
void SetMultiplayer();

/**
 * The first byte of the packet is the packet tpe
 * 1. attack packet:
 *    Bytes 2 is the number of lines attacked
 */

/**
 * The Tetris game.
 * This app will create a periodic task to update the game state.
 * When ever a button is pressed, it is handled immediately.
 */
class TetrisApp : public App {
 private:
  bool multiplayer = false;

  hitcon::tetris::TetrisGame game;
  hitcon::service::sched::PeriodicTask periodic_task;

  void RecvAttackPacket(hitcon::service::xboard::PacketCallbackArg *packet);

  uint16_t savedNonce;

  void SendGameOver();
  void SendGameOverAck(hitcon::service::xboard::PacketCallbackArg *packet);
  void UploadSingleplayerScore();
  void UploadMultiplayerScore(
      hitcon::service::xboard::PacketCallbackArg *packet);

 public:
  TetrisApp();
  virtual ~TetrisApp() = default;

  void OnEntry() override;
  void OnExit() override;
  void OnButton(button_t button) override;
  void OnXboardRecv(void *arg);
  void SetPlayerCount(unsigned playerCount);

  void periodic_task_callback(void *);
};

extern TetrisApp tetris_app;

}  // namespace tetris

}  // namespace app

}  // namespace hitcon

#endif  // TETRIS_APP_H
