/*
 * Strawberry Music Player
 * Copyright 2024, Jonas Kvinge <jonas@jkvinge.net>
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

#include <QString>

#include "core/logging.h"
#include "tagreaderloadcoverimagereply.h"

TagReaderLoadCoverImageReply::TagReaderLoadCoverImageReply(const QString &_filename, QObject *parent)
    : TagReaderReply(_filename, parent) {}

void TagReaderLoadCoverImageReply::Finish() {

  qLog(Debug) << "Finishing tagreader reply for" << filename_;

  finished_ = true;

  QMetaObject::invokeMethod(this, &TagReaderLoadCoverImageReply::EmitFinished, Qt::QueuedConnection);

}

void TagReaderLoadCoverImageReply::EmitFinished() {

  Q_EMIT TagReaderReply::Finished(filename_, result_);
  Q_EMIT TagReaderLoadCoverImageReply::Finished(filename_, image_, result_);

  QObject::disconnect(this, &TagReaderReply::Finished, nullptr, nullptr);
  QObject::disconnect(this, &TagReaderLoadCoverImageReply::Finished, nullptr, nullptr);

}