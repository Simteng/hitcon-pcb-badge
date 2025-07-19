// #define SIMU  // open if needed
#define TEST_ALL_FRAMES

#ifdef SIMU
#define SLEEP_US 500000

#include "TamaAppFrame.h"

/*--- simulation relative start---*/
/**
 * @brief The function to show the full screen in terminal. Will only use in
 * simulation.
 *
 * @param buf the frame to be displayed
 */
void display_input(const uint8_t* buf) {
  std::cout << "┌";
  for (int x = 0; x < DISPLAY_WIDTH; ++x) std::cout << "──";
  std::cout << "┐\n";

  for (int y = 0; y < DISPLAY_HEIGHT; ++y) {
    std::cout << "│";
    for (int x = 0; x < DISPLAY_WIDTH; ++x) {
      uint8_t pixel = buf[y * DISPLAY_WIDTH + x];
      std::cout << (pixel ? "██" : "  ");
      // std::cout << (pixel ? "1" : "0");
    }
    std::cout << "│\n";
  }

  std::cout << "└";
  for (int x = 0; x < DISPLAY_WIDTH; ++x) std::cout << "──";
  std::cout << "┘\n";
}

/**
 * @brief Show frame change in terminal.
 *
 * @param frame_collection A array contain frames
 * @param frame_count The len of frame_collection
 * @param delay_us How long to sleep between frames
 */
void show_anime_with_delay(const uint8_t** frame_collection, int frame_count,
                           int delay_us) {
  for (int i = 0; i < frame_count; ++i) {
    // display_input
    display_input(*(frame_collection + i));
    // delay
    usleep(delay_us);
  }
}
/*--- simulation relative end--- */

/* ------ example part ----- */
// Just examples of how to use

/**
 * @brief The example of cat_idle
 *
 * @param repeat_count How many times should frame_collection repeat
 */
void cat_idle(int repeat_count) {
  component_info cat_idle_component_info = {
      .x_len = 8,
      .y_len = 8,
      .x_offset = 0,
      .y_offset = 0,
  };
  base_info screen_info = {
      .width = 16,
      .height = 8,
  };
  const CompressedImage* target = &m_cat_idle1_compressed;
  uint8_t decompressed_buffer[target->width * target->height];
  decompress_component(target, decompressed_buffer);
  uint8_t cat_idle1[screen_info.width * screen_info.height];
  stack_component(decompressed_buffer, cat_idle1, cat_idle_component_info,
                  screen_info);

  const CompressedImage* target2 = &m_cat_idle2_compressed;
  uint8_t decompressed_buffer2[target2->width * target2->height];
  decompress_component(target2, decompressed_buffer2);
  uint8_t cat_idle2[screen_info.width * screen_info.height];
  stack_component(decompressed_buffer, cat_idle2, cat_idle_component_info,
                  screen_info);
  const uint8_t* cat_idle_frame_all[CAT_IDLE_FRAME_COUNT] = {cat_idle1,
                                                             cat_idle2};
  for (int i = 0; i < repeat_count; ++i) {
    show_anime_with_delay(cat_idle_frame_all, CAT_IDLE_FRAME_COUNT, SLEEP_US);
  }
}

/**
 * @brief The example of dog_idle
 *
 * @param repeat_count How many times should frame_collection repeat
 */
void dog_idle(int repeat_count) {
  component_info dog_idle_component_info = {
      .x_len = 8,
      .y_len = 8,
      .x_offset = 0,
      .y_offset = 0,
  };
  base_info screen_info = {
      .width = 16,
      .height = 8,
  };

  const CompressedImage* target = &m_dog_idle1_compressed;
  uint8_t decompressed_buffer[target->width * target->height];
  decompress_component(target, decompressed_buffer);
  uint8_t dog_idle1[screen_info.width * screen_info.height];
  stack_component(decompressed_buffer, dog_idle1, dog_idle_component_info,
                  screen_info);

  const CompressedImage* target2 = &m_dog_idle2_compressed;
  uint8_t decompressed_buffer2[target2->width * target2->height];
  decompress_component(target2, decompressed_buffer2);
  uint8_t dog_idle2[screen_info.width * screen_info.height];
  stack_component(decompressed_buffer, dog_idle2, dog_idle_component_info,
                  screen_info);
  const uint8_t* dog_idle_frame_all[DOG_IDLE_FRAME_COUNT] = {dog_idle1,
                                                             dog_idle2};
  for (int i = 0; i < repeat_count; ++i) {
    show_anime_with_delay(dog_idle_frame_all, DOG_IDLE_FRAME_COUNT, SLEEP_US);
  }
}

/**
 * @brief The example of select_character
 *
 * @param repeat_count How many times should frame_collection repeat
 */
void select_character(int repeat_count) {
  uint8_t select_left[DISPLAY_WIDTH * DISPLAY_HEIGHT] = {0};
  uint8_t select_right[DISPLAY_WIDTH * DISPLAY_HEIGHT] = {0};
  get_select_character_frame(LEFT, select_left);
  get_select_character_frame(RIGHT, select_right);

  const uint8_t* select_character_frame_all[SELECT_CHARACTER_FRAME_COUNT] = {
      select_left, select_right};

  // show animation
  for (int i = 0; i < repeat_count; ++i) {
    show_anime_with_delay(select_character_frame_all,
                          SELECT_CHARACTER_FRAME_COUNT, SLEEP_US);
  }
}

/**
 * @brief The example of egg hatch
 *
 * The example counts down from 390 to 0, and shows the different hatching
 * scene.
 *
 * @param repeat_count How many times should frame_collection repeat
 */
void egg_hatch(int repeat_count) {
  // demo case:
  // (remaining_count)
  // 390 > 290 > 190 > 90 > (shine1, shine2)x repeat_shine_count

  uint8_t frame1[DISPLAY_WIDTH * DISPLAY_HEIGHT] = {0};
  uint8_t frame2[DISPLAY_WIDTH * DISPLAY_HEIGHT] = {0};
  uint8_t frame3[DISPLAY_WIDTH * DISPLAY_HEIGHT] = {0};
  uint8_t frame4[DISPLAY_WIDTH * DISPLAY_HEIGHT] = {0};
  uint8_t frame5[DISPLAY_WIDTH * DISPLAY_HEIGHT] = {0};
  uint8_t frame6[DISPLAY_WIDTH * DISPLAY_HEIGHT] = {0};
  uint8_t frame7[DISPLAY_WIDTH * DISPLAY_HEIGHT] = {0};
  uint8_t frame8[DISPLAY_WIDTH * DISPLAY_HEIGHT] = {0};
  uint8_t frame9[DISPLAY_WIDTH * DISPLAY_HEIGHT] = {0};
  uint8_t frame10[DISPLAY_WIDTH * DISPLAY_HEIGHT] = {0};

  const uint8_t* frame_collection[HATCH_STATUS_FRAME_COUNT +
                                  2 * HATCH_WARNING_REPEAT_SHINE_COUNT] = {
      frame1, frame2, frame3, frame4, frame5,
      frame6, frame7, frame8, frame9, frame10};

  get_hatch_status_frame(390, frame1);
  get_hatch_status_frame(290, frame2);
  get_hatch_status_frame(190, frame3);
  get_hatch_status_frame(90, frame4);
  get_hatch_born_warning_frame(0, frame5);
  get_hatch_born_warning_frame(1, frame6);
  get_hatch_born_warning_frame(0, frame7);
  get_hatch_born_warning_frame(1, frame8);
  get_hatch_born_warning_frame(0, frame9);
  get_hatch_born_warning_frame(1, frame10);

  // show animation
  for (int i = 0; i < repeat_count; ++i) {
    show_anime_with_delay(
        frame_collection,
        HATCH_STATUS_FRAME_COUNT + 2 * HATCH_WARNING_REPEAT_SHINE_COUNT,
        SLEEP_US);
  }
}

/**
 * @brief The example of number test
 *
 * This function will show diffent digits examples of number icon, like
 * 1, 23, 456, 789, 100.
 *
 * Note: 23 can't fill like 023, or it will be recognized as octal format
 * number.
 *
 * @param repeat_count How many times should frame_collection repeat
 */
void num_test(int repeat_count) {
  const int frame_count = 5;
  const component_info num_area_component_info = {
      .x_len = 8,
      .y_len = 8,
      .x_offset = 0,
      .y_offset = 0,
  };
  const base_info screen_info = {
      .width = 16,
      .height = 8,
  };

  // create screens
  uint8_t num_component1[num_area_component_info.x_len *
                         num_area_component_info.y_len];
  memset(num_component1, 0,
         num_area_component_info.x_len * num_area_component_info.y_len);
  uint8_t num_component2[num_area_component_info.x_len *
                         num_area_component_info.y_len];
  memset(num_component2, 0,
         num_area_component_info.x_len * num_area_component_info.y_len);
  uint8_t num_component3[num_area_component_info.x_len *
                         num_area_component_info.y_len];
  memset(num_component3, 0,
         num_area_component_info.x_len * num_area_component_info.y_len);
  uint8_t num_component4[num_area_component_info.x_len *
                         num_area_component_info.y_len];
  memset(num_component4, 0,
         num_area_component_info.x_len * num_area_component_info.y_len);
  uint8_t num_component5[num_area_component_info.x_len *
                         num_area_component_info.y_len];
  memset(num_component5, 0,
         num_area_component_info.x_len * num_area_component_info.y_len);
  get_number_component(1, num_component1);
  get_number_component(23, num_component2);
  get_number_component(456, num_component3);
  get_number_component(789, num_component4);
  get_number_component(100, num_component5);

  uint8_t frame1[screen_info.width * screen_info.height];
  memset(frame1, 0, screen_info.width * screen_info.height);
  uint8_t frame2[screen_info.width * screen_info.height];
  memset(frame2, 0, screen_info.width * screen_info.height);
  uint8_t frame3[screen_info.width * screen_info.height];
  memset(frame3, 0, screen_info.width * screen_info.height);
  uint8_t frame4[screen_info.width * screen_info.height];
  memset(frame4, 0, screen_info.width * screen_info.height);
  uint8_t frame5[screen_info.width * screen_info.height];
  memset(frame5, 0, screen_info.width * screen_info.height);

  uint8_t* num_component_all[frame_count] = {num_component1, num_component2,
                                             num_component3, num_component4,
                                             num_component5};
  stack_component(num_component1, frame1, num_area_component_info, screen_info);
  stack_component(num_component2, frame2, num_area_component_info, screen_info);
  stack_component(num_component3, frame3, num_area_component_info, screen_info);
  stack_component(num_component4, frame4, num_area_component_info, screen_info);
  stack_component(num_component5, frame5, num_area_component_info, screen_info);

  const uint8_t* frame_all[frame_count] = {frame1, frame2, frame3, frame4,
                                           frame5};

  // show animation
  for (int i = 0; i < repeat_count; ++i) {
    show_anime_with_delay(frame_all, frame_count, SLEEP_US);
  }
}

/**
 * @brief The example of cat_idle
 *
 * @param repeat_count How many times should frame_collection repeat
 */
void cat_idle_with_status(int repeat_count) {
  uint8_t cat_idle1[DISPLAY_WIDTH * DISPLAY_HEIGHT] = {0};
  uint8_t cat_idle2[DISPLAY_WIDTH * DISPLAY_HEIGHT] = {0};
  get_cat_idle_frame_with_status_overview(
      FRAME_1, 3, 4, cat_idle1);  // dog idle frame with status overview
  get_cat_idle_frame_with_status_overview(
      FRAME_2, 3, 4, cat_idle2);  // dog idle frame with status overview

  const uint8_t* cat_idle_frame_all[CAT_IDLE_FRAME_COUNT] = {cat_idle1,
                                                             cat_idle2};

  for (int i = 0; i < repeat_count; ++i) {
    show_anime_with_delay(cat_idle_frame_all, CAT_IDLE_FRAME_COUNT, SLEEP_US);
  }
}

/**
 * @brief The example of dog_idle
 *
 * @param repeat_count How many times should frame_collection repeat
 */
void dog_idle_with_status(int repeat_count) {
  uint8_t dog_idle1[DISPLAY_WIDTH * DISPLAY_HEIGHT] = {0};
  uint8_t dog_idle2[DISPLAY_WIDTH * DISPLAY_HEIGHT] = {0};

  get_dog_idle_frame_with_status_overview(
      FRAME_1, 3, 4, dog_idle1);  // dog idle frame with status overview
  get_dog_idle_frame_with_status_overview(
      FRAME_2, 3, 4, dog_idle2);  // dog idle frame with status overview

  const uint8_t* dog_idle_frame_all[DOG_IDLE_FRAME_COUNT] = {dog_idle1,
                                                             dog_idle2};

  for (int i = 0; i < repeat_count; ++i) {
    show_anime_with_delay(dog_idle_frame_all, DOG_IDLE_FRAME_COUNT, SLEEP_US);
  }
}

/**
 * @brief The example of cat_idle with weak status
 *
 * Same as cat_idle_with_status, only passing value different.
 * The case here is hungry trigger weak status.
 *
 * @param repeat_count How many times should frame_collection repeat
 */
void cat_weak_idle_with_status(int repeat_count) {
  uint8_t cat_idle1[DISPLAY_WIDTH * DISPLAY_HEIGHT] = {0};
  uint8_t cat_idle2[DISPLAY_WIDTH * DISPLAY_HEIGHT] = {0};
  // cat idle frame with status overview
  get_cat_idle_frame_with_status_overview(
      FRAME_1, 3, 0, cat_idle1);  // dog idle frame with status overview
  get_cat_idle_frame_with_status_overview(
      FRAME_2, 3, 0, cat_idle2);  // dog idle frame with status overview

  const uint8_t* cat_idle_frame_all[CAT_IDLE_FRAME_COUNT] = {cat_idle1,
                                                             cat_idle2};

  for (int i = 0; i < repeat_count; ++i) {
    show_anime_with_delay(cat_idle_frame_all, CAT_IDLE_FRAME_COUNT, SLEEP_US);
  }
}

/**
 * @brief The example of dog_idle with weak status
 *
 * Same as dog_idle_with_status, only passing value different.
 * The case here is heart poor trigger weak status.
 *
 * @param repeat_count How many times should frame_collection repeat
 */

void dog_weak_idle_with_status(int repeat_count) {
  uint8_t dog_idle1[DISPLAY_WIDTH * DISPLAY_HEIGHT] = {0};
  uint8_t dog_idle2[DISPLAY_WIDTH * DISPLAY_HEIGHT] = {0};
  get_dog_idle_frame_with_status_overview(
      FRAME_1, 0, 4, dog_idle1);  // dog idle frame with status overview
  get_dog_idle_frame_with_status_overview(
      FRAME_2, 0, 4, dog_idle2);  // dog idle frame with status overview

  const uint8_t* dog_idle_frame_all[DOG_IDLE_FRAME_COUNT] = {dog_idle1,
                                                             dog_idle2};

  for (int i = 0; i < repeat_count; ++i) {
    show_anime_with_delay(dog_idle_frame_all, DOG_IDLE_FRAME_COUNT, SLEEP_US);
  }
}

void dog_status_change(int repeat_count) {
  uint8_t dog_status1[DISPLAY_WIDTH * DISPLAY_HEIGHT] = {0};
  uint8_t dog_status2[DISPLAY_WIDTH * DISPLAY_HEIGHT] = {0};
  uint8_t dog_status3[DISPLAY_WIDTH * DISPLAY_HEIGHT] = {0};

  // dog idle frame with status overview
  get_dog_idle_frame_with_status_overview(
      FRAME_1, 3, 4, dog_status1);  // dog idle frame with status overview
  get_dog_idle_frame_with_status_overview(
      FRAME_2, 2, 2, dog_status2);  // dog idle frame with status overview
  get_dog_idle_frame_with_status_overview(
      FRAME_1, 1, 0, dog_status3);  // dog idle frame with status overview

  const uint8_t* dog_idle_frame_all[3] = {dog_status1, dog_status2,
                                          dog_status3};

  for (int i = 0; i < repeat_count; ++i) {
    show_anime_with_delay(dog_idle_frame_all, 3, SLEEP_US);
  }
}

/**
 * @brief The example of pet healing
 *
 * This function will show the pet healing animation.
 *
 * @param repeat_count How many times should frame_collection repeat
 */
void pet_healing(int pet_type, int repeat_count) {
  const uint8_t frame_count = 2;
  uint8_t pet_healing1[DISPLAY_WIDTH * DISPLAY_HEIGHT] = {0};
  uint8_t pet_healing2[DISPLAY_WIDTH * DISPLAY_HEIGHT] = {0};
  get_pet_healing_frame(pet_type, FRAME_1, pet_healing1);
  get_pet_healing_frame(pet_type, FRAME_2, pet_healing2);

  // heart float up > empty
  const uint8_t* pet_healing_frame_all[frame_count] = {
      pet_healing1,
      pet_healing2,
  };

  for (int i = 0; i < repeat_count; ++i) {
    show_anime_with_delay(pet_healing_frame_all, frame_count, SLEEP_US);
  }
}

/**
 * @brief The example of training_selection
 *
 * @param repeat_count How many times should frame_collection repeat
 */
void training_selection(int repeat_count) {
  const uint8_t frame_count = 2;
  uint8_t frame_left[DISPLAY_WIDTH * DISPLAY_HEIGHT] = {0};
  uint8_t frame_right[DISPLAY_WIDTH * DISPLAY_HEIGHT] = {0};
  get_activity_selection_frame(TRAINING, LEFT, frame_left);
  get_activity_selection_frame(TRAINING, RIGHT, frame_right);

  const uint8_t* frame_all[frame_count] = {
      frame_left,
      frame_right,
  };

  for (int i = 0; i < repeat_count; ++i) {
    show_anime_with_delay(frame_all, frame_count, SLEEP_US);
  }
}

/**
 * @brief The example of battle_selection
 *
 * @param repeat_count How many times should frame_collection repeat
 */
void battle_selection(int repeat_count) {
  const uint8_t frame_count = 2;
  uint8_t frame_left[DISPLAY_WIDTH * DISPLAY_HEIGHT] = {0};
  uint8_t frame_right[DISPLAY_WIDTH * DISPLAY_HEIGHT] = {0};
  get_activity_selection_frame(BATTLE, LEFT, frame_left);
  get_activity_selection_frame(BATTLE, RIGHT, frame_right);

  const uint8_t* frame_all[frame_count] = {
      frame_left,
      frame_right,
  };

  for (int i = 0; i < repeat_count; ++i) {
    show_anime_with_delay(frame_all, frame_count, SLEEP_US);
  }
}

/**
 * @brief The example of battle_result_demo
 *
 * @param repeat_count How many times should frame_collection repeat
 */
void battle_result_demo(int pet, int result, int repeat_count) {
  const uint8_t frame_count = 2;
  uint8_t frame_1[DISPLAY_WIDTH * DISPLAY_HEIGHT] = {0};
  uint8_t frame_2[DISPLAY_WIDTH * DISPLAY_HEIGHT] = {0};
  get_battle_result_frame(pet, result, FRAME_1, frame_1);
  get_battle_result_frame(pet, result, FRAME_2, frame_2);

  const uint8_t* frame_all[frame_count] = {
      frame_1,
      frame_2,
  };

  for (int i = 0; i < repeat_count; ++i) {
    show_anime_with_delay(frame_all, frame_count, SLEEP_US);
  }
}

void battle_demo(int player_pet, int enemy_pet, int attack_first,
                 int repeat_count) {
  const uint8_t frame_count = 5;

  int damage_target_order1, damage_target_order2;
  if (attack_first == PLAYER) {
    damage_target_order1 = ENEMY;
    damage_target_order2 = PLAYER;
  } else {
    damage_target_order1 = PLAYER;
    damage_target_order2 = ENEMY;
  }

  uint8_t frame1[DISPLAY_WIDTH * DISPLAY_HEIGHT] = {0};
  uint8_t frame2[DISPLAY_WIDTH * DISPLAY_HEIGHT] = {0};
  uint8_t frame3[DISPLAY_WIDTH * DISPLAY_HEIGHT] = {0};
  uint8_t frame4[DISPLAY_WIDTH * DISPLAY_HEIGHT] = {0};
  uint8_t frame5[DISPLAY_WIDTH * DISPLAY_HEIGHT] = {0};
  get_battle_frame(player_pet, enemy_pet, NONE, frame1);
  get_battle_frame(player_pet, enemy_pet, damage_target_order1, frame2);
  get_battle_frame(player_pet, enemy_pet, NONE, frame3);
  get_battle_frame(player_pet, enemy_pet, damage_target_order2, frame4);
  get_battle_frame(player_pet, enemy_pet, NONE, frame5);
  const uint8_t* frame_all[frame_count] = {frame1, frame2, frame3, frame4,
                                           frame5};

  for (int i = 0; i < repeat_count; ++i) {
    show_anime_with_delay(frame_all, frame_count, SLEEP_US);
  }
}

void training_demo(int pet_type, int repeat_count) {
  const uint8_t frame_count = 3;

  uint8_t frame1[DISPLAY_WIDTH * DISPLAY_HEIGHT] = {0};
  uint8_t frame2[DISPLAY_WIDTH * DISPLAY_HEIGHT] = {0};
  uint8_t frame3[DISPLAY_WIDTH * DISPLAY_HEIGHT] = {0};

  get_battle_frame(pet_type, OTHER_TYPE_TRAINING_FACILITY, NONE, frame1);
  get_battle_frame(pet_type, OTHER_TYPE_TRAINING_FACILITY, ENEMY, frame2);
  get_battle_frame(pet_type, OTHER_TYPE_TRAINING_FACILITY, NONE, frame3);

  const uint8_t* frame_all[frame_count] = {frame1, frame2, frame3};

  for (int i = 0; i < repeat_count; ++i) {
    show_anime_with_delay(frame_all, frame_count, SLEEP_US);
  }
}

void detail_information_demo(int repeat_count) {
  const uint8_t frame_count = 12;

  uint8_t frame1[DISPLAY_WIDTH * DISPLAY_HEIGHT] = {0};
  uint8_t frame2[DISPLAY_WIDTH * DISPLAY_HEIGHT] = {0};
  uint8_t frame3[DISPLAY_WIDTH * DISPLAY_HEIGHT] = {0};
  uint8_t frame4[DISPLAY_WIDTH * DISPLAY_HEIGHT] = {0};
  uint8_t frame5[DISPLAY_WIDTH * DISPLAY_HEIGHT] = {0};
  uint8_t frame6[DISPLAY_WIDTH * DISPLAY_HEIGHT] = {0};
  uint8_t frame7[DISPLAY_WIDTH * DISPLAY_HEIGHT] = {0};
  uint8_t frame8[DISPLAY_WIDTH * DISPLAY_HEIGHT] = {0};
  uint8_t frame9[DISPLAY_WIDTH * DISPLAY_HEIGHT] = {0};
  uint8_t frame10[DISPLAY_WIDTH * DISPLAY_HEIGHT] = {0};
  uint8_t frame11[DISPLAY_WIDTH * DISPLAY_HEIGHT] = {0};
  uint8_t frame12[DISPLAY_WIDTH * DISPLAY_HEIGHT] = {0};

  get_LV_status_frame(999, frame1);
  get_LV_status_frame(32, frame2);
  get_LV_status_frame(1, frame3);
  get_FD_status_frame(4, frame4);
  get_FD_status_frame(3, frame5);
  get_FD_status_frame(2, frame6);
  get_FD_status_frame(1, frame7);
  get_FD_status_frame(0, frame8);
  get_HP_status_frame(3, frame9);
  get_HP_status_frame(2, frame10);
  get_HP_status_frame(1, frame11);
  get_HP_status_frame(0, frame12);

  const uint8_t* frame_all[frame_count] = {frame1, frame2,  frame3,  frame4,
                                           frame5, frame6,  frame7,  frame8,
                                           frame9, frame10, frame11, frame12};

  for (int i = 0; i < repeat_count; ++i) {
    show_anime_with_delay(frame_all, frame_count, SLEEP_US);
  }
}

void feed_confirm_demo(int repeat_count) {
  const uint8_t frame_count = 2;

  uint8_t frame_left[DISPLAY_WIDTH * DISPLAY_HEIGHT] = {0};
  uint8_t frame_right[DISPLAY_WIDTH * DISPLAY_HEIGHT] = {0};
  get_feed_confirm_frame(LEFT, frame_left);
  get_feed_confirm_frame(RIGHT, frame_right);

  const uint8_t* frame_all[frame_count] = {frame_left, frame_right};

  for (int i = 0; i < repeat_count; ++i) {
    show_anime_with_delay(frame_all, frame_count, SLEEP_US);
  }
}

void feed_pet_demo(int pet_type, int repeat_count) {
  const uint8_t frame_count = 10;

  uint8_t feed_pet_frame1[DISPLAY_WIDTH * DISPLAY_HEIGHT] = {0};
  uint8_t feed_pet_frame2[DISPLAY_WIDTH * DISPLAY_HEIGHT] = {0};
  uint8_t feed_pet_frame3[DISPLAY_WIDTH * DISPLAY_HEIGHT] = {0};
  uint8_t feed_pet_frame4[DISPLAY_WIDTH * DISPLAY_HEIGHT] = {0};
  uint8_t pet_happy_frame_after_feed1[DISPLAY_WIDTH * DISPLAY_HEIGHT] = {0};
  uint8_t pet_happy_frame_after_feed2[DISPLAY_WIDTH * DISPLAY_HEIGHT] = {0};
  uint8_t pet_happy_frame_after_feed3[DISPLAY_WIDTH * DISPLAY_HEIGHT] = {0};
  uint8_t pet_happy_frame_after_feed4[DISPLAY_WIDTH * DISPLAY_HEIGHT] = {0};
  uint8_t pet_happy_frame_after_feed5[DISPLAY_WIDTH * DISPLAY_HEIGHT] = {0};
  uint8_t pet_happy_frame_after_feed6[DISPLAY_WIDTH * DISPLAY_HEIGHT] = {0};

  get_feed_pet_frame(cookie_100, feed_pet_frame1);
  get_feed_pet_frame(cookie_50, feed_pet_frame2);
  get_feed_pet_frame(cookie_30, feed_pet_frame3);
  get_feed_pet_frame(cookie_0, feed_pet_frame4);
  get_pet_happy_frame_after_feed(pet_type, FRAME_1,
                                 pet_happy_frame_after_feed1);
  get_pet_happy_frame_after_feed(pet_type, FRAME_2,
                                 pet_happy_frame_after_feed2);
  get_pet_happy_frame_after_feed(pet_type, FRAME_1,
                                 pet_happy_frame_after_feed3);
  get_pet_happy_frame_after_feed(pet_type, FRAME_2,
                                 pet_happy_frame_after_feed4);
  get_pet_happy_frame_after_feed(pet_type, FRAME_1,
                                 pet_happy_frame_after_feed5);
  get_pet_happy_frame_after_feed(pet_type, FRAME_2,
                                 pet_happy_frame_after_feed6);

  const uint8_t* frame_all[frame_count] = {feed_pet_frame1,
                                           feed_pet_frame2,
                                           feed_pet_frame3,
                                           feed_pet_frame4,
                                           pet_happy_frame_after_feed1,
                                           pet_happy_frame_after_feed2,
                                           pet_happy_frame_after_feed3,
                                           pet_happy_frame_after_feed4,
                                           pet_happy_frame_after_feed5,
                                           pet_happy_frame_after_feed6};

  for (int i = 0; i < repeat_count; ++i) {
    show_anime_with_delay(frame_all, frame_count, SLEEP_US);
  }
}

void scoring_then_end_demo(int repeat_count) {
  const uint8_t frame_count = 6;

  uint8_t scoring_frame1[DISPLAY_WIDTH * DISPLAY_HEIGHT] = {0};
  uint8_t scoring_frame2[DISPLAY_WIDTH * DISPLAY_HEIGHT] = {0};
  uint8_t end_frame1[DISPLAY_WIDTH * DISPLAY_HEIGHT] = {0};
  uint8_t empty_frame1[DISPLAY_WIDTH * DISPLAY_HEIGHT] = {0};
  uint8_t end_frame2[DISPLAY_WIDTH * DISPLAY_HEIGHT] = {0};
  uint8_t empty_frame2[DISPLAY_WIDTH * DISPLAY_HEIGHT] = {0};

  get_scoring_frame(5, 0, scoring_frame1);
  get_scoring_frame(0, 5, scoring_frame2);
  get_end_frame(end_frame1);
  get_empty_frame(empty_frame1);
  get_end_frame(end_frame2);
  get_empty_frame(empty_frame2);

  const uint8_t* frame_all[frame_count] = {scoring_frame1, scoring_frame2,
                                           end_frame1,     empty_frame1,
                                           end_frame2,     empty_frame2};

  for (int i = 0; i < repeat_count; ++i) {
    show_anime_with_delay(frame_all, frame_count, SLEEP_US);
  }
}

void test_frames() {
  int repeat_count = 3;
  int repeat_once = 1;

#ifdef TEST_ALL_FRAMES

  // cat idle demo
  // std::cout << "Cat Idle Demo:\n";
  // cat_idle(repeat_count);

  // dog idle demo
  // std::cout << "Dog Idle Demo:\n";
  // dog_idle(repeat_count);

  // selection demo
  std::cout << "Select Character Demo:\n";
  select_character(repeat_count);

  // number icon demo
  // std::cout << "Number Icon Demo:\n";
  // num_test(repeat_once);

  // egg hatch demo
  std::cout << "Egg Hatch Demo:\n";
  egg_hatch(repeat_once);

  // cat idle demo with status
  std::cout << "Cat Idle Demo with status:\n";
  cat_idle_with_status(repeat_count);

  // dog idle demo with status
  std::cout << "Dog Idle Demo with status:\n";
  dog_idle_with_status(repeat_count);

  // dog idle demo with status
  // std::cout << "Dog status change Demo:\n";
  // dog_status_change(repeat_count);

  // cat idle demo with status
  std::cout << "Cat Weak Idle Demo with status:\n";
  cat_weak_idle_with_status(repeat_count);

  // dog idle demo with status
  std::cout << "Dog Weak Idle Demo with status:\n";
  dog_weak_idle_with_status(repeat_count);

  // dog healing demo
  std::cout << "Dog healing Demo:\n";
  pet_healing(PET_TYPE_DOG, repeat_count);

  // cat healing demo
  std::cout << "Cat healing Demo:\n";
  pet_healing(PET_TYPE_CAT, repeat_count);

  // training selection demo
  std::cout << "training_selection Demo:\n";
  training_selection(repeat_count);

  // battle selection demo
  std::cout << "battle_selection Demo:\n";
  battle_selection(repeat_count);

  // dog battle result win demo
  std::cout << "Dog battle result win Demo:\n";
  battle_result_demo(PET_TYPE_DOG, WIN, repeat_count);

  // dog battle result lose demo
  std::cout << "Dog battle result lose Demo:\n";
  battle_result_demo(PET_TYPE_DOG, LOSE, repeat_count);

  // cat battle result win demo
  std::cout << "Cat battle result win Demo:\n";
  battle_result_demo(PET_TYPE_CAT, WIN, repeat_count);

  // cat battle result lose demo
  std::cout << "Cat battle result lose Demo:\n";
  battle_result_demo(PET_TYPE_CAT, LOSE, repeat_count);

  // dog-dog battle demo
  std::cout << "Dog-Dog battle Demo:\n";
  battle_demo(PET_TYPE_DOG, PET_TYPE_DOG, PLAYER, repeat_count);

  // dog-cat battle demo
  std::cout << "Dog-Cat battle Demo:\n";
  battle_demo(PET_TYPE_DOG, PET_TYPE_CAT, ENEMY, repeat_count);

  // cat-dog battle demo
  std::cout << "Cat-Dog battle Demo:\n";
  battle_demo(PET_TYPE_CAT, PET_TYPE_DOG, PLAYER, repeat_count);

  // cat-cat battle demo
  std::cout << "Cat-Cat battle Demo:\n";
  battle_demo(PET_TYPE_CAT, PET_TYPE_CAT, ENEMY, repeat_count);

  // dog training demo
  std::cout << "Dog training Demo:\n";
  training_demo(PET_TYPE_DOG, repeat_count);
  // cat training demo
  std::cout << "Cat training Demo:\n";
  training_demo(PET_TYPE_CAT, repeat_count);

  // detail information demo
  std::cout << "Pet detail information Demo:\n";
  detail_information_demo(repeat_once);

  // feed confirm demo
  std::cout << "Feed confirm Demo:\n";
  feed_confirm_demo(repeat_count);

  // feed pet demo
  std::cout << "Feed pet Demo:\n";
  feed_pet_demo(PET_TYPE_DOG, repeat_once);
  feed_pet_demo(PET_TYPE_CAT, repeat_once);

#endif  // TEST_ALL_FRAMES

  // scoring and end demo
  std::cout << "Scoring then end Demo:\n";
  scoring_then_end_demo(repeat_count);
}

void test_compress_decompress() {
  //---- compress part, can use for converting image to compressed data ---
  compress_data_and_print_info(m_example_of_compress, 8, 8);

  //---- decompress part, can use for verifying compressed data ----
  // constexpr uint8_t hardcoded_compressed_data[] = {0x38, 0xE0, 0x70, 0xF8,
  //                                                  0x7C, 0xF8, 0x7C, 0x10};

  // CompressedImage hardcoded_compressed_image = {
  //     .width = 8, .height = 8, .data = hardcoded_compressed_data};

  // decompress_and_print_component(&hardcoded_compressed_image);
}

int main() {
  // test_frames();

  test_compress_decompress();  // open it if needed
  return 0;
}

#endif
