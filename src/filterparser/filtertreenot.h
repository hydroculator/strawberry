/*
 * Strawberry Music Player
 * This file was part of Clementine.
 * Copyright 2012, David Sansome <me@davidsansome.com>
 * Copyright 2018-2024, Jonas Kvinge <jonas@jkvinge.net>
 *
 * Strawberry is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Strawberry is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Strawberry.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef FILTERTREENOT_H
#define FILTERTREENOT_H

#include <QScopedPointer>

#include "filtertree.h"

#include "core/song.h"

class FilterTreeNot : public FilterTree {
 public:
  explicit FilterTreeNot(const FilterTree *inv);

  FilterType type() const override { return FilterType::Not; }
  bool accept(const Song &song) const override;

 private:
  QScopedPointer<const FilterTree> child_;

  Q_DISABLE_COPY(FilterTreeNot)
};

#endif  // FILTERTREENOT_H
