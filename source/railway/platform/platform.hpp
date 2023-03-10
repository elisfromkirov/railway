#pragma once

#include <railway/core/core.hpp>

namespace railway {

namespace platform {

/**
 * @brief Makes TCP socket, establishes TCP connection to endpoint specified by address and port.
 *
 * @return TCP socket's handle
 */
int Connect(uint address, ushort port);

/**
 * @brief Makes TCP socket, marks it as listener on endpoint specified by address and port.
 *
 * @return TCP socket's handle
 */
int Listen(uint address, ushort port);

/**
 * @brief Closes file, socket or pipe specified by handle.
 */
void Close(int handle);

/**
 * @brief Reads at most size bytes from file, socket or pipe specified by handle to buffer.
 */
ulong Read(int handle, char* buffer, ulong size);

/**
 * @brief Writes size bytes from buffer to file, socket or pipe specified by handle.
 */
ulong Write(int handle, const char* buffer, ulong size);

/**
 * @biref Represents i/o event.
 */
struct Event {
  /**
   * @brief Notifies that reading is available.
   */
  bool reading_available;

  /**
   * @brief Notifies that writing is available.
   */
  bool writing_available;

  /**
   * @brief User defined state.
   */
  void* state;
};

/**
 * @brief Makes i/o notification queue.
 *
 * @return i/o notification queue handle.
 */
int MakePoll();

/**
 * @brief Polls i/o notification queue specified by handle.
 *
 * @return Number of polled events.
 */
ulong Poll(int poll, Event* event, ulong size);

/**
 * @brief Adds handle with state to i/o notification queue.
 */
void EnqueueHandle(int poll, int handle, void* state);

/**
 * @brief Removes handle from i/o notification queue.
 */
void DequeueHandle(int poll, int handle);

}  // namespace platform

}  // namespace railway